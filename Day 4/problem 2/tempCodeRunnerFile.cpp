#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, int>> directions = {
    {-1, -1},  // Top-left
    {-1, 1},   // Top-right
    {1, -1},   // Bottom-left
    {1, 1}     // Bottom-right
};

// Function to check if the pattern "X-MAS" starts at the given position (row, col)
bool findXMASPattern(vector<string> &grid, int row, int col) {
    int n = grid.size();
    int m = grid[0].size();
    
    // Check if the current position is a valid center (should be 'A')
    if (grid[row][col] != 'A') {
        return false;
    }

    // Try all four diagonal directions for the X-MAS pattern
    for (auto& dir : directions) {
        int dirX = dir.first;
        int dirY = dir.second;

        // Check the X-MAS pattern in this direction
        if (row - dirX >= 0 && row + dirX < n && col - dirY >= 0 && col + dirY < m &&
            grid[row - dirX][col - dirY] == 'M' && grid[row + dirX][col + dirY] == 'S' &&
            grid[row - 2 * dirX][col - 2 * dirY] == 'M' && grid[row + 2 * dirX][col + 2 * dirY] == 'S') {
            return true;
        }
    }

    return false;
}

// Function to count all occurrences of the X-MAS pattern in the grid
int countXMASOccurrences(vector<string> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;

    // Iterate over each cell in the grid
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            // Check if an X-MAS pattern starts from this cell
            if (findXMASPattern(grid, row, col)) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    string filename = "input2.txt";  // Specify the input file
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

    // Count occurrences of the X-MAS pattern
    int result = countXMASOccurrences(grid);

    cout << "The X-MAS pattern appears " << result << " times in the grid." << endl;

    return 0;
}
