#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

double EPS = 1e-9;

int main() {
    while (true) {
        int k, n, e;
        scanf("%d %d %d", &k, &n, &e);
        if (k == 0 && n == 0 && e == 0) {
            break;
        }

        int numNodes = (int) pow(2, n);
        vector<vector<int>> G(numNodes, vector<int>());
        for (int i = 0; i < e; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        vector<vector<double>> probs(2, vector<double>(numNodes, 0));
        for (int i = 0; i < numNodes; ++i) {
            probs[0][i] = 1.0 / numNodes;
        }
        bool good = true;
        for (int j = 1; j < k && good; ++j) {
            for (int i = 0; i < numNodes; ++i) {
                probs[j % 2][i] = 0;
            }
            for (int i = 0; i < numNodes; ++i) {
                auto &neigh = G[i];
                for (int to : neigh) {
                    probs[j % 2][to] += probs[(j - 1) % 2][i] / neigh.size();
                }
            }
            vector<double> bitprob(n, 0);
            for (int i = 0; i < numNodes; ++i) {
                double p = probs[j % 2][i];
                bitset<32> b(i);
                for (int r = 0; r < n; ++r) {
                    if (b[r]) {
                        bitprob[r] += p;
                    }
                }
            }
            for (double p : bitprob) {
                if (p < 0.25 + EPS || p > 0.75 - EPS) {
                    good = false;
                }
            }
        }

        if (good) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
}
