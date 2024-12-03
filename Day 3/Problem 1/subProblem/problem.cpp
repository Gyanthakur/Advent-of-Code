

#include <iostream>
#include <fstream>  // For file handling
#include <string>   // For string handling

using namespace std;

int main() {
    // Declare a variable to store the sum
    long long sum = 0;
    
    // Create an input file stream object to read the file
    ifstream inputFile("inputmul.txt");
    
    // Check if the file is open
    if (!inputFile) {
        cerr << "Unable to open file" << endl;
        return 1;  // Exit if the file cannot be opened
    }

    long long num;
    // Read numbers from the file and add them to sum
    while (inputFile >> num) {
        sum += num;
    }

    // Close the file
    inputFile.close();

    // Output the total sum
    cout << "The total sum is: " << sum << endl;

    return 0;
}
