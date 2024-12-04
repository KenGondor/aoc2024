#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


bool checkSafety(vector<int> &levels)
{
    bool decreasing = false;
    bool increasing = false;
    int prev = levels[0];
    for (int i = 1; i < levels.size(); ++i)
    {
        int distance = levels[i] - prev;
        if (distance > 0) {
            increasing = true;
        }
        if (distance < 0) {
            decreasing = true;
        }

        distance = std::abs(distance);
        if (distance > 3 || distance < 1) {
            decreasing = true;
            increasing = true;
            break;
        }
        prev = levels[i];
    }

    if (!increasing || !decreasing) {
        return true;
    } else {
        return false;
    }
}

bool checkAgain(vector<int> &levels)
{
    // brute force approach
    // 1. create a new vector with removed element
    int n = levels.size();
    for (int i = 0; i < n; i++)
    {
        int removed = levels[i];
        vector<int> removedLevels;

        // create new vector
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            removedLevels.push_back(levels[j]);
        }

        if (checkSafety(removedLevels)) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream ifile("input.txt");
    string line;
    int safe = 0;
    while (getline( ifile, line)) {
        istringstream iss(line);
        vector<int> v;
        int level;
        while (iss >> level) {
            v.push_back(level);
        }

        if (checkSafety(v) || checkAgain(v)) {
            safe++;
        }
    }

    cout << safe << endl;
    return 0;
}
