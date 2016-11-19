#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

pair<bool, vector<string>> solve(map<string, set<string>> &g) {
    map<string, set<string>> reverse;
    for (auto &kv : g) {
        for (auto &v : kv.second) {
            reverse[v].insert(kv.first);
        }
    }
    priority_queue<string, vector<string>, std::greater<string>> install_queue;
    for (auto &kv : g) {
        if (kv.second.empty()) {
            install_queue.push(kv.first);
        }
    }
    vector<string> install_order;
    while (!install_queue.empty()) {
        string v = install_queue.top();
        install_queue.pop();
        install_order.push_back(v);
        for (auto &depends : reverse[v]) {
            g[depends].erase(v);
            if (g[depends].empty()) {
                install_queue.push(depends);
            }
        }
    }
    if (install_order.size() < g.size()) {
        return {false, vector<string>()};
    }
    return {true, install_order};
}

set<string> tokenize(string &s) {
    set<string> r;
    stringstream ss(s);
    string w;
    while (ss >> w) {
        r.insert(w);
    }
    return r;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        map<string, set<string>> g;
        for (int i = 0; i < n; ++i) {
            string package;
            cin >> package;
            string line;
            getline(cin, line);
            g[package] = tokenize(line);
        }
        auto r = solve(g);
        if (r.first) {
            for (auto p : r.second) {
                cout << p << endl;
            }
        } else {
            cout << "cannot be ordered" << endl;
        }
        cout << endl;
    }
}
