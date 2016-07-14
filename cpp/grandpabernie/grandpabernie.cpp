#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    map<string, vector<int>> m;
    for (int i = 0; i < n; ++i) {
        char country[20];
        int y;
        scanf("%s %d", country, &y);
        m[country].push_back(y);
    }

    for (auto &p : m) {
        sort(p.second.begin(), p.second.end());
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        char country[20];
        int k;
        scanf("%s %d", country, &k);
        printf("%d\n", m[country][k - 1]);
    }
}

