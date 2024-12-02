// https://adventofcode.com/2024/day/1
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    vector<int> leftList, rightList;
    int leftNum, rightNum;

    while (inputFile >> leftNum >> rightNum)
    {
        leftList.push_back(leftNum);
        rightList.push_back(rightNum);
    }

    inputFile.close();

    sort(leftList.begin(), leftList.end());
    sort(rightList.begin(), rightList.end());

    int totalDistance = 0;
    for (size_t i = 0; i < leftList.size(); ++i)
    {
        totalDistance += abs(leftList[i] - rightList[i]);
    }

    cout << "Total distance between the lists: " << totalDistance << endl;

    return 0;
}
