README

This README file provides detailed instructions for compiling and running the Search Engine Project

# Project Description
Search Engine project is aimed at developing a system that enables efficient searching and retrieval of relevant documents based on user queries. The purpose of this project is to provide a tool that can handle a collection of documents, build an inverted index, and perform search operations to retrieve documents that satisfy the user's query.

# Compilation Instructions
Ensure that you have a C++ compiler installed on your system. If you don't have one, you can install GCC (GNU Compiler Collection) for your operating system.

## For Linux:
Open a terminal and run the following command to install GCC:
sudo apt-get install build-essential

## For macOS:
Install Xcode Command Line Tools by opening a terminal and running the following command:
### xcode-select --install

## For Windows:
Install MinGW (Minimalist GNU for Windows) by following the instructions on the official website: (https://mingw-w64.org/doku.php)
Download the code files to your local machine. You can either clone the repository or download the code as a ZIP file and extract it to a directory of your choice.
Open a terminal or command prompt and navigate to the directory where the code files are located using the cd command.
Compile the code using the following command:
### g++ -o search main.cpp
This command will invoke the C++ compiler (g++) to compile the main.cpp file and generate an executable file named "search" in the same directory.

If the compilation is successful, you should see the "search" executable file in the directory.

# Running Instructions
Make sure you have compiled the code as mentioned in the Compilation Instructions section.
Prepare a text file containing the documents you want to search. Each document should be on a separate line. The file should not contain any HTML or XML tags.
Save the text file as "data.txt" in the same directory as the compiled executable.
Open a terminal or command prompt and navigate to the directory where the compiled executable is located using the cd command.
Run the code using the following command:
### ./search
This command will execute the "search" executable and start the program.
The code will read the "data.txt" file, build an inverted index, and perform search queries.
The program will display the following prompt:
Query:
Enter a query to search for documents. The query should be a space-separated sequence of words.
After entering a query, the program will display the search results.
You can enter additional queries one after another. The program will continue to prompt for queries until you choose to exit.
To exit the program, you can press Ctrl+C or close the terminal/command prompt window.


# Using Visual Studio Code (VS Code)  IDE
Ensure that you have Visual Studio Code installed on your system. If you don't have it, you can download it from the official website: (https://code.visualstudio.com/.)
Download the code files to your local machine. You can either clone the repository or download the code as a ZIP file and extract it to a directory of your choice.
Open Visual Studio Code and navigate to the project directory by selecting File > Open Folder and selecting the folder containing the code files.
Open a terminal in VS Code by selecting View > Terminal.
Compile the code using the following command:
### g++ -o search main.cpp
This command will invoke the C++ compiler (g++) to compile the main.cpp file and generate an executable file named "search" in the same directory.
If the compilation is successful, you should see the "search" executable file in the directory.
![Getting Started](/Screenshot%20(93).png)
# Using Visual Studio IDE
Ensure that you have Visual Studio installed on your system. If you don't have it, you can download it from the official website: (https://visualstudio.microsoft.com/.)
Download the code files to your local machine. You can either clone the repository or download the code as a ZIP file and extract it to a directory of your choice.
Open Visual Studio and select File > Open > Project/Solution.
Navigate to the directory where you extracted the code files and select the project file (e.g., .sln file) to open the project in Visual Studio.
Build the project by selecting Build > Build Solution.
If the build is successful, you should see the "search" executable file generated in the build output directory.

# Running Instructions
Make sure you have compiled the code as mentioned in the Compilation Instructions section.
Prepare a text file containing the documents you want to search. Each document should be on a separate line. The file should not contain any HTML or XML tags.

Example of "data.txt" file:
This is the content of document 1.
Save the text file as "data.txt" in the same directory as the compiled executable.

Open a terminal or command prompt in the project directory.

# Running in VS Code
Run the code using the following command:
### ./search
This command will execute the "search" executable and start the program.
![Getting Started](/Screenshot%20(94).png)
# Running in Visual Studio
Set the program arguments to include the path to the "data.txt" file. In Visual Studio, you can do this by right-clicking on the project, selecting Properties, navigating to Debugging, and entering the path in the Command Arguments field (e.g., data.txt).

Press F5 or select Start Debugging to run the program.


Note: If you encounter any issues during compilation or execution, make sure you have the necessary permissions to compile and run the code. Also, ensure that the "data.txt" file is in the correct format and located in the same directory as the compiled executable.
