#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    map<int, int> arrows;
    int r = 0;
    for (int i = 0; i < n; ++i) {
        int balloon;
        scanf("%d", &balloon);
        if (arrows[balloon] > 0) {
            arrows[balloon] -= 1;
        } else {
            r += 1;
        }
        arrows[balloon - 1] += 1;
    }
    printf("%d\n", r);
}

