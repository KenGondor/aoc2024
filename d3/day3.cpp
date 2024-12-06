#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    ifstream ifile("input.txt");
    string line;
    int total_sum = 0;

    while (getline( ifile, line))
    {
        regex mul_regex("mul\\((\\d{1,3}),(\\d{1,3})\\)");
        regex do_regex("do\\(\\)");
        regex dont_regex("don't\\(\\)");
        sregex_token_iterator startMatch(
            line.begin(),
            line.end(),
            regex("mul\\(\\d{1,3},\\d{1,3}\\)|do\\(\\)|don't\\(\\)"));
        sregex_token_iterator endMatch;

        bool enabled = true;

        for (; startMatch != endMatch; ++startMatch)
        {
            string token = *startMatch;

            if (regex_match(token, mul_regex))
            {
                if (!enabled) continue;

                smatch match;

                regex_match(token, match, mul_regex);

                string x = match[1].str();
                string y = match[2].str();


                total_sum = total_sum + stoi(x) * stoi(y);
                cout << "X: " + x + ", Y: " + y << ", Current Sum: " << total_sum << endl;

            }
            else if (regex_match(token, do_regex))
            {
                enabled = true;
            }
            else if (regex_match(token, dont_regex))
            {
                enabled = false;
            }
        }
    }

    cout << total_sum << endl;
    return total_sum;
}
