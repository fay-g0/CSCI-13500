#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string inputFileName, searchWord, replaceWord;
    int replacementCount = 0;
    int totalWords = 0;
    
    // Get user input
    cout << "Enter the input file name: ";
    cin >> inputFileName;
    
    cout << "Enter the word to search for: ";
    cin >> searchWord;
    
    cout << "Enter the replacement word: ";
    cin >> replaceWord;
    
    // Open input file
    ifstream inputFile(inputFileName.c_str());
    
    // Check if file opened successfully
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file '" << inputFileName << "'" << endl;
        return 1;
    }
    
    // Open output file
    ofstream outputFile("output.txt");
    
    // Check if output file opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error: Could not create output.txt" << endl;
        inputFile.close();
        return 1;
    }
    
    // Read and process the file word by word
    string word;
    bool firstWord = true;
    
    while (inputFile >> word) {
        totalWords++;
        
        // Check if current word matches the search word
        if (word == searchWord) {
            // Replace with replacement word
            outputFile << replaceWord;
            replacementCount++;
        } else {
            // Keep the word unchanged
            outputFile << word;
        }
    }
    outputFile.close();
    outputFile.open("output.txt");
    
    // Reset file pointer to beginning
    inputFile.clear();
    inputFile.seekg(0, ios::beg);
    
    replacementCount = 0;
    totalWords = 0;
    bool firstWordWritten = false;
    
    // Process the file again with proper spacing
    while (inputFile >> word) {
        totalWords++;
        
        // Add space before word if it's not the first word
        if (firstWordWritten) {
            outputFile << " ";
        }
        
        // Check if current word matches the search word
        if (word == searchWord) {
            outputFile << replaceWord;
            replacementCount++;
        } else {
            outputFile << word;
        }
        
        firstWordWritten = true;
    }
    
    // Close the files
    inputFile.close();
    outputFile.close();
    
    //results
    cout << "The word \"" << searchWord << "\" was found " << replacementCount << " times." << endl;
    cout << "The modified text has been saved to output.txt." << endl;
    
    //total words processed
    cout << "Total words processed: " << totalWords << endl;
    
    //percentage of words replaced
    if (totalWords > 0) {
        double percentage = (static_cast<double>(replacementCount) / totalWords) * 100;
        cout << "Percentage of words replaced: " << percentage << "%" << endl;
    }
    
    return 0;
}