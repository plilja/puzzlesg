#include <iostream>
#include <set>

using namespace std;

int main() {
    int k, m;
    while (2 == scanf("%d %d", &k, &m)) {
        set<int> courses;
        for (int i = 0; i < k; ++i) {
            int t;
            scanf("%d", &t);
            courses.insert(t);
        }
        bool requirements_met = true;
        for (int i = 0; i < m; ++i) {
            int c, r;
            scanf("%d %d", &c, &r);
            int in_category = 0;
            for (int j = 0; j < c; ++j) {
                int t;
                scanf("%d", &t);
                if (courses.count(t) > 0) {
                    in_category++;
                }
            }
            requirements_met = requirements_met && (in_category >= r);
        }
        if (requirements_met) {
            puts("yes");
        } else {
            puts("no");
        }
    }
}
