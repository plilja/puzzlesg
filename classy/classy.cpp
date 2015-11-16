#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

typedef long long ll;

vector<string> split(string &s, char delim)
{
    vector<string> res;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        res.push_back(item);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<pair<ll, string>> people(n);
        for (int j = 0; j < n; ++j) {
            string name, classStr, foo;
            cin >> name >> classStr >> foo;
            name = name.substr(0, name.size() - 1);
            vector<string> cl = split(classStr, '-');
            ll val = 0;
            for (int i = 0; i < (int)cl.size(); ++i) {
                string &s = cl[i];
                ll coeff;
                if (s[0] == 'l') {
                    coeff = 0;
                } else if (s[0] == 'm') {
                    coeff = 1;
                } else {
                    coeff = 2;
                }
                val += coeff * pow(10L, 9 - cl.size() + i + 1);
            }
            for (int i = cl.size(); i < 10; ++i) {
                val += pow(10L, 9 - i);
            }
            people[j] = {-val, name};
        }
        sort(people.begin(), people.end());

        for (auto &p : people) {
            cout << p.second << endl;
        }
        cout << "==============================" << endl;
    }
}


