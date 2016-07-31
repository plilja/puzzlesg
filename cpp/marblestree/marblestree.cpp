#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void compute_cost(int n, vector<vector<int>> &children, vector<int> &marbles, vector<int> &cost, int i) {
    if (cost[i] != -1) {
        return;
    }
    for (int c: children[i]) {
        compute_cost(n, children, marbles, cost, c);
    }
    int r = abs(marbles[i]) - 1;
    int a = marbles[i];
    for (int c: children[i]) {
        if (marbles[c] > 1) {
            r = r + marbles[c] - 1;
            a = a + marbles[c] - 1;
        } else if (marbles[c] < 1) {
            r = r - marbles[c] + 1;
            a = a + marbles[c] - 1;
        }
    }
    cost[i] = r;
    marbles[i] = a;
}

int main() {
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        vector<int> marbles(n, 0);
        vector<vector<int>> children(n, vector<int>());
        for (int i = 0; i < n; ++i) {
            int v, m, d;
            scanf("%d %d %d", &v, &m, &d);
            v--;
            marbles[v] = m;
            for (int j = 0; j < d; ++j) {
                int a;
                scanf("%d", &a);
                a--;
                children[v].push_back(a);
            }
        }
        vector<int> cost(n, -1);
        for (int i = 0; i < n; ++i) {
            compute_cost(n, children, marbles, cost, i);
        }
        int r = 0;
        for (auto c : cost) {
            r += c;
        }
        printf("%d\n", r);
    }
}

