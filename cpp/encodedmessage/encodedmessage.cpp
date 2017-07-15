#include <iostream>
#include <cmath>
#include <cstring>

int main()
{
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; ++_) {
        char encoded[10003], 
             decoded[10003];
        scanf("%s", encoded);
        int n = strlen(encoded);
        decoded[n] = '\0';
        int sq = (int) sqrt(n);
        for (int i = 0; i < sq; ++i) {
            for (int j = 0; j < sq; ++j) {
                decoded[i*sq + j] = encoded[j*sq + sq - 1 - i];
            }
        }
        printf("%s\n", decoded);
    }
}
