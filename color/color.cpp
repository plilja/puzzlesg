#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int s, c, k;
    scanf("%d %d %d", &s, &c, &k);
    vector<int> socks(s);
    for (int i = 0; i < s; ++i) {
        scanf("%d", &socks[i]);
    }
    sort(socks.begin(), socks.end());
    int num_machines = 0;
    int prev = -k - 1;
    int load = 0;
    for (int i : socks) {
        if (i > prev + k || load == c) {
            prev = i;
            num_machines++;
            load = 1;
        } else {
            load++;
        }
    }
    printf("%d\n", num_machines);
}
