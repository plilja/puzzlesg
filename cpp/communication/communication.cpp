#include <iostream>

using namespace std;

typedef unsigned char uchar;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        uchar b = tmp;
        int d = 255;
        for (uchar j = 0; j < 255; ++j) {
            uchar t = (j ^ (j << 1));
            if (b == t) {
                d = j;
                break;
            }
        }
        printf("%d", (int)d);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}
