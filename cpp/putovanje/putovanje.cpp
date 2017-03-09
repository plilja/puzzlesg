#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, c;
    scanf("%d %d", &n, &c);
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int weight_eaten = 0;
        int num_eaten = 0;
        for (int j = i; j < n; ++j) {
            if (weight_eaten + w[j] <= c) {
                weight_eaten += w[j];
                num_eaten++;
            }
        }
        ans = max(ans, num_eaten);
    }
    printf("%d\n", ans);
}
