// https://adventofcode.com/2024/day/1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cerr << "Error opening input file!" << endl;
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

    unordered_map<int, int> rightFrequency;
    for (int num : rightList)
    {
        rightFrequency[num]++;
    }

    int similarityScore = 0;
    for (int num : leftList)
    {
        similarityScore += num * rightFrequency[num];
    }

    cout << "Total similarity score: " << similarityScore << endl;

    return 0;
}
