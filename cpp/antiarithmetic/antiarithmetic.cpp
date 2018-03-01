#include <iostream>
#include <vector>

using namespace std;

bool is_antiarithmetic(vector<short> &numbers) {
    int n = (int) numbers.size();
    vector<short> idx(n, -1);
    for (short i = 0; i < n; ++i) {
        idx[numbers[i]] = i;
    }
    for (short i = 0; i < n - 2; ++i) {
        int a = numbers[i];
        for (short j = i + 2; j < n; ++j) {
            int b = numbers[j];
            int d = b - a;
            if (d % 2 == 0) {
                int expected_middle = a + d / 2;
                short k = idx[expected_middle];
                if (i < k && k < j) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        scanf(":");
        vector<short> numbers(n);
        for (int i = 0; i < n; ++i) {
            scanf("%hd", &numbers[i]);
        }
        if (is_antiarithmetic(numbers)) {
            puts("yes");
        } else {
            puts("no");
        }
    }
}
