#include <iostream>
#include "disjoint_set.h"
#include <vector>
#include <set>

using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    DisjointSet ds(n);
    set<int> sat;
    for (int i = 0; i < m; ++i) {
        vector<int> neigh;
        for (int j = 0; j < n; ++j) {
            int a;
            cin >> a;
            if (a == 0) {
                sat.insert(j);
                neigh.push_back(j);
            }
        }
        for (int v1 : neigh) {
            for (int v2 : neigh) {
                ds.merge(v1, v2);
            }
        }
    }
    if (ds.count() <= k && sat.size() == n) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}