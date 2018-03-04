#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    map<string, set<int>> item_to_store;
    for (int j = 0; j < k; ++j) {
        int i;
        char s[13];
        scanf("%d %s", &i, s);
        item_to_store[s].insert(i);
    }
    int m;
    scanf("%d", &m);
    map<int, int> current_position;
    current_position[-1] = 1;
    for (int i = 0; i < m; ++i) {
        char s[13];
        scanf("%s", s);
        map<int, int> new_current_position;
        int r = 0;
        for (int j : item_to_store[s]) {
            for (auto p : current_position) {
                if (j >= p.first) {
                    new_current_position[j] += p.second;
                    r += p.second;
                }
            }
            if (r > 1) {
                break;
            }
        }
        current_position = new_current_position;
    }
    int answers = 0;
    for (auto p : current_position) {
        answers += p.second;
    }
    if (answers == 0) {
        puts("impossible");
    } else if (answers == 1) {
        puts("unique");
    } else {
        puts("ambiguous");
    }
}
