#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

//#include <bits/stdc++.h>

using namespace std;

int main() {
    // Open the input file
    ifstream infile("input.txt");
    vector<int> leftList;
    vector<int> rightList;
    string line;
    int left, right;

    // Read numbers into leftList
    while (getline(infile, line)) {
        istringstream iss(line);
        iss >> left;
        iss >> right;
        cout << left << " , " << right << endl;
        leftList.push_back(left);
        rightList.push_back(right);
    }

    sort(leftList.begin(), leftList.end());
    sort(rightList.begin(), rightList.end());

    int result = 0;

    // for part 2
    unordered_map<int, int> leftMap;
    unordered_map<int, int> rightMap;
    for (int i = 0; i < leftList.size(); i++) {
        result += std::abs(leftList[i] - rightList[i]);
        leftMap[leftList[i]]++;
        rightMap[rightList[i]]++;
    }

    int secondResult;
    for (int i = 0; i < leftList.size(); i++) {
        secondResult += rightMap[leftList[i]] * leftList[i];
    }
    cout << "Part 1: " << result << ", Part 2: " << secondResult << endl;
}
