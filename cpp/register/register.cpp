#include <iostream>
#include <vector>

using namespace std;

int PRIMES[] = {2, 3, 5, 7, 11, 13, 17, 19};

int main()
{
    vector<int> registers(8);
    for (int i = 0; i < 8; ++i) {
        scanf("%d", &registers[i]);
    }
    vector<int> positional(8, 1);
    for (int i = 1; i < 8; ++i) {
        positional[i] = positional[i - 1] * PRIMES[i - 1];
    }
    int r = 0;
    for (int i = 0; i < 8; ++i) {
        r += (PRIMES[i] - registers[i] - 1) * positional[i];
    }
    printf("%d\n", r);
}
