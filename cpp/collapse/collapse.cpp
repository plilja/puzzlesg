#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> survival(n);
    vector<int> receives(n, 0);
    vector<vector<pii>> gives_to(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &survival[i]);
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            int neigh, v;
            scanf("%d %d", &neigh, &v);
            neigh--; // make zero indexed
            gives_to[neigh].push_back({i, v});
            receives[i] += v;
        }
    }

    queue<int> deaths;
    deaths.push(0); // Incunabula
    receives[0] = -1;

    // Check if any islands aren't receiving enough goods already from the start
    for (int i = 1; i < n; ++i) {
        if (receives[i] < survival[i]) {
            deaths.push(i);
        }
    }

    int survivors = n;
    while (!deaths.empty()) {
        int d = deaths.front();
        deaths.pop();
        survivors--;
        for (auto p : gives_to[d]) {
            // Is still alive?
            if (receives[p.first] >= survival[p.first]) {
                receives[p.first] -= p.second;
                if (receives[p.first] < survival[p.first]) {
                    deaths.push(p.first);
                }
            }
        }
    }

    printf("%d\n", survivors);
}
