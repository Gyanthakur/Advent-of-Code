#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Function to check if a diagonal forms "MAS" or "SAM"
bool isMASorSAM(char a, char b, char c) {
    string pattern = {a, b, c};
    return (pattern == "MAS" || pattern == "SAM");
}

int countXMAS(const vector<string>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    // Traverse the grid to find potential centers of the X
    for (int i = 1; i < rows - 1; i++) {       // Avoid the first and last rows
        for (int j = 1; j < cols - 1; j++) {   // Avoid the first and last columns
            // Check top-left to bottom-right diagonal
            if (isMASorSAM(grid[i - 1][j - 1], grid[i][j], grid[i + 1][j + 1]) &&
                isMASorSAM(grid[i + 1][j - 1], grid[i][j], grid[i - 1][j + 1])) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<string> grid;
    ifstream inputFile("input.txt");

    // Check if file opened successfully
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input.txt file!" << endl;
        return 1;
    }

    // Read grid from the file
    string line;
    while (getline(inputFile, line)) {
        grid.push_back(line);
    }
    inputFile.close();

    // Count X-MAS patterns
    int result = countXMAS(grid);
    cout << "Number of X-MAS patterns: " << result << endl;

    return 0;
}