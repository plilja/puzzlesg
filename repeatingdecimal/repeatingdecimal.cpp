#include <iostream>

int main()
{
    int a, b, c;
    while (3 == scanf("%d %d %d", &a, &b, &c)) {
        int r = 10 * a;
        printf("0.");
        for (int i = 0; i < c; ++i) {
            int q = r / b;
            r = r % b;
            r *= 10;
            printf("%d", q);
        }
        puts("");
    }
}
