#include <iostream>

int main()
{
    int M, P, L, E, R, S, N;
    while (7 == scanf("%d %d %d %d %d %d %d", &M, &P, &L, &E, &R, &S, &N)) {
        for (int i = 0; i < N; ++i) {
            int new_mosquitos = P / S;
            P = L / R;
            L = M * E;
            M = new_mosquitos;
        }
        printf("%d\n", M);
    }
}
