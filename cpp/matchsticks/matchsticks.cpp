#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int costs[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

long long smallest(int n)
{
    if (n <= 7) {
        for (int i = 1; i <= 9; ++i) {
            if (costs[i] == n) {
                return i;
            }
        }
        throw -1; // should never happen
    } else if (n == 8)
        return 10;
    else if (n == 10)
        return 22;
    else if (n == 11)
        return 20;
    else if (n == 17)
        return 200;
    else
        return 10 * smallest(n - 7) + 8;
}

string largest(int n)
{
    if (n == 2)
        return "1";
    if (n == 3)
        return "7";
    return largest(n - 2) + "1";
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        cout << smallest(n) << " " << largest(n) << endl;
    }
}

