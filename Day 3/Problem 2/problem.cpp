#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string filename = "input.txt";  // Specify your input file name here
    
    // Open the file
    ifstream inputFile(filename);
    
    if (!inputFile) {
        cerr << "Error opening file " << filename << endl;
        return 1;
    }

    // Read the entire contents of the file into a string
    string instructions;
    getline(inputFile, instructions, '\0');  // Read till end of file

    inputFile.close();  // Close the file after reading

    bool mulEnabled = true;  // Initially, mul is enabled
    int totalSum = 0;

    size_t i = 0;
    while (i < instructions.size()) {
        if (instructions[i] == 'd' && i + 3 < instructions.size() && instructions.substr(i, 4) == "do()") {
            mulEnabled = true;  // Enable mul
            i += 4;
        }
        else if (instructions[i] == 'd' && i + 4 < instructions.size() && instructions.substr(i, 5) == "don't") {
            mulEnabled = false;  // Disable mul
            i += 5;
        }
        else if (instructions[i] == 'm' && i + 3 < instructions.size() && instructions.substr(i, 3) == "mul") {
            // Extract the numbers within mul()
            i += 3;  // Skip "mul"
            if (i < instructions.size() && instructions[i] == '(') {
                i++;  // Skip '('
                int num1 = 0, num2 = 0;
                while (i < instructions.size() && isdigit(instructions[i])) {
                    num1 = num1 * 10 + (instructions[i] - '0');
                    i++;
                }
                if (i < instructions.size() && instructions[i] == ',') {
                    i++;  // Skip ','
                    while (i < instructions.size() && isdigit(instructions[i])) {
                        num2 = num2 * 10 + (instructions[i] - '0');
                        i++;
                    }
                }
                if (i < instructions.size() && instructions[i] == ')') {
                    i++;  // Skip ')'
                    
                    // Only process if mul is enabled
                    if (mulEnabled) {
                        totalSum += num1 * num2;
                    }
                }
            }
        }
        else {
            i++;  // Skip over non-relevant characters
        }
    }
    
    cout << "Total sum of enabled multiplications: " << totalSum << endl;
    
    return 0;
}
