#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    unordered_set<string> dict;
    while (getline(cin, line)) {
        istringstream iss(line);
        string w;
        while (iss >> w) {
            string lowered = w;
            transform(lowered.begin(), lowered.end(), lowered.begin(), ::tolower);
            auto it = dict.find(lowered);
            if (it == dict.end()) {
                dict.insert(lowered);
                cout << w << " ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

