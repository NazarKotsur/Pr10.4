#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Failed to open file!" << endl;
        return 1;
    }

    string line;
    int totalWords = 0;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;
        string shortestWord;
        int wordCount = 0;
        bool firstWord = true;

        while (iss >> word) {
            wordCount++;
            if (firstWord) {
                shortestWord = word;
                firstWord = false;
            }
            else {
                if (word.length() < shortestWord.length()) {
                    shortestWord = word;
                }
            }
        }

        totalWords += wordCount;

        outputFile << shortestWord << endl;
    }

    outputFile << totalWords << endl;

    inputFile.close();
    outputFile.close();

    cout << "The results are recorded in output.txt" << endl;

    return 0;
}
