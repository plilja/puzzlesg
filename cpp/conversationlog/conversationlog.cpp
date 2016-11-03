#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

int main()
{
    int n;
    scanf("%d\n", &n);
    unordered_map<string, int> word_freq;
    unordered_map<string, set<string>> word_to_users;
    set<string> users;

    for (int i = 0; i < n; ++i) {
        char line[2000000];
        fgets(line, 2000000, stdin);
        stringstream ss(line);
        string user, s;
        ss >> user;
        users.insert(user);
        while (ss >> s) {
            word_freq[s] += 1;
            word_to_users[s].insert(user);
        }
    }

    vector<pair<int, string>> v;
    for (auto &kv : word_freq) {
        if (word_to_users[kv.first].size() == users.size()) {
            v.push_back({-kv.second, kv.first});
        }
    }
    if (v.size() == 0) {
        puts("ALL CLEAR");
    } else {
        sort(v.begin(), v.end());
        for (auto &p : v) {
            printf("%s\n", p.second.c_str());
        }
    }
}
