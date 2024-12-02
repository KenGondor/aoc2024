#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

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

        bool decreasing = false;
        bool increasing = false;
        int prev = v[0];
        for (int i = 1; i < v.size(); i++) {
            // check for monotonicity
            // and the at least 1 and at most 3 between adjacent
            int distance = v[i] - prev;
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
            prev = v[i];
        }

        if (!increasing || !decreasing) {
            safe++;
        }
    }

    cout << safe << endl;
    return 0;
}
