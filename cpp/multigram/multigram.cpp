#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool test(char *s, int n, int k) {
    vector<int> v1('z' - 'a' + 1, 0);
    for (int i = 0; i < k; ++i) {
        v1[s[i] - 'a'] += 1;
    }
    for (int i = 1; i < n / k; ++i) {
        vector<int> v2('z' - 'a' + 1, 0);
        for (int j = 0; j < k; ++j) {
            v2[s[k * i + j] - 'a'] += 1;
        }
        for (char j = 'a'; j <= 'z'; ++j) {
            if (v1[j - 'a'] != v2[j - 'a']) {
                return false;
            }
        }
    }
    return true;
}

int main() 
{
    char s[100003];
    scanf("%s", s);
    int n = strlen(s);
    vector<int> freq('z' - 'a' + 1, 0);
    for (int i = 0; i < n; ++i) {
        freq[s[i] - 'a'] += 1;
    }
    int ans = -1;
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i != 0) {
            continue;
        }
        bool poss = true;
        for (char j = 'a'; j <= 'z'; ++j) {
            if (freq[j - 'a'] % (n / i) != 0) {
                poss = false;
                break;
            }
        }
        if (poss) {
            if (test(s, n, i)) {
                ans = i;
                break;
            }
        }
    }
    if (ans == -1) {
        puts("-1");
    } else {
        for (int i = 0; i < ans; ++i) {
            printf("%c", s[i]);
        }
        printf("\n");
    }
}
