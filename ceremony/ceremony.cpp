#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> buildings(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &buildings[i]);
    }
    sort(buildings.begin(), buildings.end());
    int r = buildings.size();
    for (int i = 0; i < (int)buildings.size(); ++i) {
        int horizontal_booms = buildings[i];
        int vertical_booms = buildings.size() - i - 1;
        r = min(r, horizontal_booms + vertical_booms);

    }
    printf("%d\n", r);
}
