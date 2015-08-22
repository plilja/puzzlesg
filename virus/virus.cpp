#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char l1[100003];
    char l2[100003];
    scanf("%s\n", l1);
    scanf("%s\n", l2);
    int n1 = strlen(l1);
    int n2 = strlen(l2);
    int left = 0;
    while (left < n1 && left < n2 && l1[left] == l2[left]) {
        left++;
    }
    int right = 0, r1 = n1 - 1, r2 = n2 - 1;
    while (r1 >= 0 && r2 >= 0 && l1[r1] == l2[r2]) {
        right++;
        r1--;
        r2--;
    }
    int ans = max(n2 - n1, max(0, n2 - left - right));
    printf("%d\n", ans);
}
