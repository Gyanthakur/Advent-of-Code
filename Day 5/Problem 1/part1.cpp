#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Function to check if an update is valid based on the rules
bool isValidUpdate(const vector<int>& update, const unordered_map<int, unordered_set<int>>& rules) {
    unordered_map<int, int> position;
    for (int i = 0; i < update.size(); ++i) {
        position[update[i]] = i; // Store positions of pages in the update
    }
    for (const auto& rule : rules) {
        int x = rule.first; // Rule's "before" page
        const unordered_set<int>& ySet = rule.second; // Pages that must come after
        if (position.find(x) != position.end()) { // Check if x is in the update
            for (int y : ySet) { // Iterate over all y values
                if (position.find(y) != position.end() && position[x] > position[y]) {
                    return false; // Rule violated
                }
            }
        }
    }
    return true;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error: Cannot open input file." << endl;
        return 1;
    }

    string line;
    unordered_map<int, unordered_set<int>> rules;
    vector<vector<int>> updates;

    // Read rules
    while (getline(inputFile, line) && !line.empty()) {
        istringstream iss(line);
        string rule;
        int x, y;
        if (getline(iss, rule, '|')) {
            x = stoi(rule);
            iss >> y;
            rules[x].insert(y); // Add rule x|y to the map
        }
    }

    // Read updates
    while (getline(inputFile, line)) {
        istringstream iss(line);
        vector<int> update;
        string page;
        while (getline(iss, page, ',')) {
            update.push_back(stoi(page));
        }
        updates.push_back(update); // Add update to the list of updates
    }

    inputFile.close();

    int sumMiddlePages = 0;

    for (const auto& update : updates) {
        if (isValidUpdate(update, rules)) {
            int middleIndex = update.size() / 2; // Find the middle index
            sumMiddlePages += update[middleIndex]; // Add the middle page to the sum
        }
    }

    cout << "Sum of middle pages for correctly ordered updates: " << sumMiddlePages << endl;

    return 0;
}
