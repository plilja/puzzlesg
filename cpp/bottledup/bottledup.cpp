#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000001;

int main()
{
    int s, v1, v2;
    scanf("%d %d %d", &s, &v1, &v2);
    vector<int> m1(s + 1, INF);
    vector<pair<int, int>> m2(s + 1);
    m1[0] = 0;
    m2[0] = {0, 0};
    for (int i = min(v1, v2); i <= s; ++i) {
        if (i >= v1 && m1[i] > m1[i - v1] + 1) {
            m1[i] = m1[i - v1] + 1;
            auto p = m2[i - v1];
            m2[i] = {p.first + 1, p.second};
        }
        if (i >= v2 && m1[i] > m1[i - v2] + 1) {
            m1[i] = m1[i - v2] + 1;
            auto p = m2[i - v2];
            m2[i] = {p.first, p.second + 1};
        }
    }
    if (m1[s] < INF) {
        auto p = m2[s];
        printf("%d %d\n", p.first, p.second);
    } else {
        puts("Impossible");
    }
}
