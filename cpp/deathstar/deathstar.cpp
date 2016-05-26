#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int t;
            scanf("%d", &t);
            v[i] |= t;
            v[j] |= t;
        }
    }
    for (int i : v) {
        printf("%d ", i);
    }
    puts("");
}
