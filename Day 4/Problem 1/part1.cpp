#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

 vector<pair<int, int>> directions = {
    {0, 1},  {0, -1},  
    {1, 0},  {-1, 0},  
    {1, 1},  {1, -1},  
    {-1, 1}, {-1, -1} 
};

bool findWord( vector<string> &grid, int row, int col,  string &word, int dirX, int dirY) {
    int n = grid.size();
    int m = grid[0].size();
    int wordLen = word.size();

    for (int k = 0; k < wordLen; ++k) {
        int newRow = row + k * dirX;
        int newCol = col + k * dirY;

        // Check boundaries
        if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || grid[newRow][newCol] != word[k]) {
            return false;
        }
    }

    return true;
}

int countWordOccurrences( vector<string> &grid,  string &word) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            // Check for the word in all 8 directions
            for (int i = 0; i < directions.size(); ++i) {
                int dirX = directions[i].first;
                int dirY = directions[i].second;

                if (findWord(grid, row, col, word, dirX, dirY)) {
                    count++;
                }
            }
        }
    }

    return count;
}

int main() {
    string filename = "input.txt";  // Specify the input file
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error opening file " << filename << endl;
        return 1;
    }

    vector<string> grid;
    string line;

    // Read the grid from the file
    while (getline(inputFile, line)) {
        grid.push_back(line);
    }

    inputFile.close();

    // Word to search for
    string word = "XMAS";

    // Count occurrences of the word
    int result = countWordOccurrences(grid, word);

    cout << "The word " << word << " appears " << result << " times in the grid." << endl;

    return 0;
}
