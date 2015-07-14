#include <vector>
#include <iostream>

using namespace std;

const int M = 1000003;

int solve(int n, int m)
{
    vector<pair<vector<int>, vector<int>>> combos;
    combos.push_back({vector<int>(), vector<int>()});
    for (int i = 0; i < n; ++i) {
        combos[0].first.push_back(i);
        combos[0].second.push_back(i);
    }
    for (int e = 0; e < m; ++e) {
        char switches[1002], lights[1002];
        fgets(switches, 1002, stdin);
        fgets(lights, 1002, stdin);

        auto tmp = combos;
        combos.clear();
        for (auto &combo : tmp) {
            vector<int> on_switches;
            vector<int> off_switches;
            vector<int> on_lights;
            vector<int> off_lights;
            for (int a : combo.first) {
                if (switches[a] == '1')
                    on_switches.push_back(a);
                else
                    off_switches.push_back(a);
            }
            for (int a : combo.second) {
                if (lights[a] == '1')
                    on_lights.push_back(a);
                else
                    off_lights.push_back(a);
            }
            if (on_switches.size() != on_lights.size() ||
                off_switches.size() != off_lights.size()) {
                return 0;
            }
            int num_covered = 0;
            if (!on_switches.empty() && !on_lights.empty()) {
                combos.push_back({on_switches, on_lights});
                num_covered += on_switches.size();
            }
            if (!off_switches.empty() && !off_lights.empty()) {
                combos.push_back({off_switches, off_lights});
                num_covered += off_switches.size();
            }
            if (num_covered != (int)combo.first.size())
                return 0;
        }
    }
    int ans = 1;
    for (auto &combo : combos) {
        for (int i = 2; i <= (int)combo.first.size(); ++i) {
            ans = (ans * i) % M;

        }
    }
    return ans;
}

int main()
{
    int n, m;
    scanf("%d %d\n", &n, &m);
    int ans = solve(n, m);
    printf("%d\n", ans);

}

