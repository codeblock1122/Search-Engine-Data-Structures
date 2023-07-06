#include <iostream> // for cout, cin 
#include <fstream> //for file handling  
#include <string> // for string class 
#include <vector> // for vector (dynamic array) 
#include <unordered_map> // for unordered_map (hash table) 
#include <algorithm> // for set_intersection and back_inserter functions 

using namespace std;

// Structure is used to store the document ID and content
struct Document { 
    string id;
    string content;
};

// Tokenize a string into words
vector<string> tokenize(const string& str) {
    vector<string> tokens;
    string word;
    for (const char& c : str) { // Iterate over each character in the string
        if (isalpha(c)) { // Check if the character is an alphabet
            word.push_back(tolower(c)); // Converting string to lowercase
        } else {
            if (!word.empty()) { // Check if the word is not empty
                tokens.push_back(word); // Adding word to the vector
                word.clear(); // Clearing the word
            }
        }
    }
    if (!word.empty()) { // Check if the word is not empty
        tokens.push_back(word); // Adding word to the vector
    }
    return tokens;
}

// Build inverted index from a collection of documents
unordered_map<string, vector<string>> buildInvertedIndex(const vector<Document>& documents) {
    unordered_map<string, vector<string>> invertedIndex;
    
    // Iterate over each document in the collection
    for (const auto& doc : documents) {
        // Tokenize the content of the document into words
        vector<string> tokens = tokenize(doc.content); // tokenize function is called
        
        // Update the inverted index with the document ID for each token
        for (const auto& token : tokens) { // Iterate over each token   
            invertedIndex[token].push_back(doc.id); // Adding the document ID to the vector
        }
    }
    
    return invertedIndex;
}

// Retrieve documents that satisfy the query
vector<string> searchDocuments(const unordered_map<string, vector<string>>& invertedIndex, const string& query) {
    vector<string> result;
    vector<string> keywords = tokenize(query); // tokenize function is called

    // Retrieve documents for each keyword
    vector<vector<string>> documentLists;
    for (const auto& keyword : keywords) { // Iterate over each keyword
        // Check if the keyword exists in the inverted index
        if (invertedIndex.count(keyword) > 0) { // count function is called
            // Retrieve the list of document IDs associated with the keyword
            documentLists.push_back(invertedIndex.at(keyword)); // at function helps to retrieve the value associated with the key
        }
    }

    // Apply AND and OR operations
    if (!documentLists.empty()) {
        // Start with the document list for the first keyword
        result = documentLists[0]; // Assigning the first document list to the result vector

        // Iterate over the remaining document lists and find the intersection
        for (size_t i = 1; i < documentLists.size(); ++i) {
            vector<string> intersection;
            
            // Find the intersection of the current result and the current document list
            set_intersection(result.begin(), result.end(), documentLists[i].begin(), documentLists[i].end(),
                                  back_inserter(intersection)); //// back_inserter function helps to insert the elements at the end of the vector
            result = intersection;
        }
    }

    return result;
}

int main() {
    // Read documents from file
    vector<Document> documents; // vector of Document structure
    ifstream inputFile("data.txt");
    if (inputFile) {
        string line;
        while (getline(inputFile, line)) {
            // Exclude empty lines and lines starting with '<'
            if (!line.empty() && line[0] != '<') {
                Document doc;
                // Assign a unique ID to each document
                doc.id = "Doc" + to_string(documents.size() + 1);
                doc.content = line;
                documents.push_back(doc);
            }
        }
        inputFile.close();
    } else {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    // Build the inverted index
    unordered_map<string, vector<string>> invertedIndex = buildInvertedIndex(documents); // buildInvertedIndex function is called

    // Example queries
    vector<string> queries = { 
        "flow",
        "flow AND stream",
        "flow OR stream",
        "supersonic AND speeds",
        "the AND boundary AND layer",
        "boundary-layer",
        "velocity OR speed",
        "(optional) reynolds AND number OR reynolds AND numbers"
    };

    // Perform search for each query
    for (const auto& query : queries) {
        cout << "Query: " << query << endl;

        // Retrieve the documents that satisfy the query
        vector<string> results = searchDocuments(invertedIndex, query);

        // Print the search results
        if (results.empty()) {
            cout << "No documents found." << endl;
        } else {
            cout << "Documents found: ";
            for (const auto& doc : results) {
                cout << doc << " ";
            }
            cout << endl;
        }

        cout << "----------------------------------------" << endl;
    }

    return 0;
}
