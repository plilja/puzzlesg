#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

pair<vi, vi> solve(vi &boxes, int s1, int s2)
{
    for (int i = 0; i < (int)boxes.size(); ++i) {
        int b1 = boxes[i];
        for (int j = i + 1; j < (int)boxes.size(); ++j) {
            int b2 = boxes[j];
            for (int h = j + 1; h < (int)boxes.size(); ++h) {
                int b3 = boxes[h];
                if (b1 + b2 + b3 == s1) {
                    vi sol1(3);
                    sol1[0] = b1;
                    sol1[1] = b2;
                    sol1[2] = b3;
                    vi sol2;
                    for (auto b : boxes) {
                        if (b != b1 && b != b2 && b != b3) {
                            sol2.push_back(b);
                        }
                    }
                    sort(sol1.begin(), sol1.end(), std::greater<int>());
                    sort(sol2.begin(), sol2.end(), std::greater<int>());
                    return {sol1, sol2};
                }
            }
        }
    }
    return {vector<int>(), vector<int>()};
}

int main()
{
    vi boxes(6);
    for (int i = 0; i < 6; ++i) {
        scanf("%d", &boxes[i]);
    }
    int s1, s2;
    scanf("%d %d", &s1, &s2);
    auto sol = solve(boxes, s1, s2);
    for (auto b : sol.first) {
        printf("%d ", b);
    }
    for (auto b : sol.second) {
        printf("%d ", b);
    }
    puts("");
}
