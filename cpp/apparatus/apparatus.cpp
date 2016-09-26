#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

const int M = 1000003;

int solve(int n, int m) {
    vector<pair<vector<int>, vector<int>>> pairing_groups;
    pairing_groups.push_back({vector<int>(), vector<int>()});
    for (int i = 0; i < n; ++i) {
        // Initial assumption is any switch can connect with any light
        pairing_groups[0].first.push_back(i);
        pairing_groups[0].second.push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        char switches[1002], lights[1002];
        fgets(switches, 1002, stdin);
        fgets(lights, 1002, stdin);

        vector<pair<vector<int>, vector<int>>> new_pairing_groups;
        for (auto &pairing_group: pairing_groups) {
            vector<int> on_switches;
            vector<int> off_switches;
            vector<int> on_lights;
            vector<int> off_lights;
            for (int k : pairing_group.first) {
                if (switches[k] == '1') {
                    on_switches.push_back(k);
                } else {
                    off_switches.push_back(k);
                }
            }
            for (int k : pairing_group.second) {
                if (lights[k] == '1') {
                    on_lights.push_back(k);
                } else {
                    off_lights.push_back(k);
                }
            }
            if (on_switches.size() != on_lights.size()) {
                // inconsistency with previous information
                return 0;
            }
            assert(off_switches.size() == off_lights.size());

            if (!on_switches.empty()) {
                new_pairing_groups.push_back({on_switches, on_lights});
            }
            if (!off_switches.empty()) {
                new_pairing_groups.push_back({off_switches, off_lights});
            }
        }
        pairing_groups = new_pairing_groups;
    }

    int ans = 1;
    for (auto &pairing_group : pairing_groups) {
        for (int i = 2; i <= (int) pairing_group.first.size(); ++i) {
            ans = (ans * i) % M;
        }
    }
    return ans;
}

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    int ans = solve(n, m);
    printf("%d\n", ans);
}