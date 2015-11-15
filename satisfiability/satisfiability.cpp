#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <cmath>
#include <sstream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n, m;
        cin >> n >> m;
        scanf("%d %d", &n, &m);
        vector<vector<int>> clauses(2 * n);
        for (int j = 0; j < m; ++j) {
            string line;
            getline(cin, line);
            istringstream iss(line);
            string var;
            while (iss >> var) {
                if (var[0] == 'v') {
                    continue;
                }
                if (var[0] == '~') {
                    int v = stoi(var.substr(2, string::npos));
                    clauses[n + v - 1].push_back(j);
                } else {
                    int v = stoi(var.substr(1, string::npos));
                    clauses[v - 1].push_back(j);
                }
            }
        }
        int lim = pow(2, n) - 1;
        bool possible = false;
        for (int i = 0; i <= lim && !possible; ++i) {
            bitset<20> vars(i);
            vector<bool> satisfied(m, false);
            for (int j = 0; j < n; ++j) {
                bool var = vars[j];
                if (var) {
                    for (int c : clauses[j]) {
                        satisfied[c] = true;
                    }
                } else {
                    for (int c : clauses[n + j]) {
                        satisfied[c] = true;
                    }
                }
            }
            bool all_satisfied = true;
            for (auto b : satisfied) {
                all_satisfied = all_satisfied && b;
            }
            possible = possible || all_satisfied;
        }
        if (possible) {
            cout << "satisfiable" << endl;
        } else {
            cout << "unsatisfiable" << endl;
        }
    }
}
