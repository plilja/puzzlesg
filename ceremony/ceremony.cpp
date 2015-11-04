#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int HIGHEST = 1000000;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> buildings(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &buildings[i]);
    }
    sort(buildings.begin(), buildings.end());
    vector<int> heights(HIGHEST + 1, 0);
    int curr = 0;
    int j = 1;
    for (int i = 0; i < n; ++i) {
        if (i < n - 1 && buildings[i] == buildings[i + 1]) {
            continue;
        }
        curr = buildings[i];
        while (j < curr) {
            heights[j] = heights[j - 1];
            j++;
        }
        heights[j] = i + 1;
        j++;
    }
    int r = HIGHEST + 1;
    for (int i = 0; i <= HIGHEST; ++i) {
        int num_heigher_than_i = n - heights[i];
        int c = i + num_heigher_than_i;
        if (c < r) {
            r = c;
        }
    }
    printf("%d\n", r);
}
