// https://adventofcode.com/2024/day/2

#include <bits/stdc++.h>
using namespace std;

bool isSafe(const vector<int> &levels)
{
    vector<int> differences;

    for (size_t i = 0; i < levels.size() - 1; ++i)
    {
        differences.push_back(levels[i + 1] - levels[i]);
    }

    bool isIncreasing = true, isDecreasing = true;

    for (int diff : differences)
    {
        if (diff < 1 || diff > 3)
        {
            isIncreasing = false;
        }
        if (diff > -1 || diff < -3)
        {
            isDecreasing = false;
        }
    }

    return isIncreasing || isDecreasing;
}

bool isSafeWithDampener(const vector<int> &levels)
{
    if (isSafe(levels))
        return true;

    for (size_t i = 0; i < levels.size(); ++i)
    {
        vector<int> modifiedLevels = levels;
        modifiedLevels.erase(modifiedLevels.begin() + i); // Remove the i-th level

        if (isSafe(modifiedLevels))
            return true;
    }

    return false;
}

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    string line;
    int safeCount = 0;

    while (getline(inputFile, line))
    {
        istringstream lineStream(line);
        vector<int> levels;
        int level;

        while (lineStream >> level)
        {
            levels.push_back(level);
        }

        if (isSafeWithDampener(levels))
        {
            ++safeCount;
        }
    }

    inputFile.close();

    cout << "Number of safe reports with the Problem Dampener: " << safeCount << endl;

    return 0;
}
