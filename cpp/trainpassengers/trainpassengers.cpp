#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int c, n;
    scanf("%d %d", &c, &n);
    int passengers = 0;
    bool consistent = true;
    for (int i = 0; i < n; ++i) {
        int left, entered, stayed;
        scanf("%d %d %d", &left, &entered, &stayed);
        passengers = passengers - left + entered;
        if (passengers > c || passengers < 0 || (passengers < c && stayed > 0)) {
            consistent = false;
            break;
        }
        if (i == 0 && left > 0) {
            consistent = false;
            break;
        }
        if (i == n - 1 && (entered > 0 || stayed > 0)) {
            consistent = false;
        }
    }
    if (passengers > 0) {
        consistent = false;
    }
    if (consistent) {
        puts("possible");
    } else {
        puts("impossible");
    }

}
