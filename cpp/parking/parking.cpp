#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> prices(4, 0),
                minutes(101, 0);
    scanf("%d %d %d", &prices[1], &prices[2], &prices[3]);
    for (int i = 0; i < 3; ++i) {
        int arr, dep;
        scanf("%d %d", &arr, &dep);
        for (int m = arr; m < dep; ++m) {
            minutes[m]++;
        }
    }
    int price = 0;
    for (int m : minutes) {
        price += m*prices[m];
    }
    printf("%d\n", price);
}
