#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int NUM_ELEMS = 114;
char table[][3] = {
    "li", "be", "b", "c", "n", "o", "f", "ne",
    "na", "mg", "al", "si", "p", "s", "cl", "ar",
    "k", "ca", "sc", "ti", "v", "cr", "mn", "fe",
    "co", "ni", "cu", "zn", "ga", "ge", "as", "se",
    "br", "kr","rb", "sr", "y", "zr", "nb", "mo",
    "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn",
    "sb", "te", "i", "xe", "cs", "ba", "hf", "ta",
    "w", "re", "os", "ir", "pt", "au", "hg", "tl",
    "pb", "bi", "po", "at", "rn", "fr", "ra", "rf",
    "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn",
    "fl", "lv","la", "ce", "pr", "nd", "pm", "sm",
    "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb",
    "lu", "ac", "th", "pa", "u", "np", "pu", "am",
    "cm", "bk", "cf", "es", "fm", "md", "no", "lr",
    "h", "he",
};

int main() {
    int t;
    scanf("%d", &t);
    char s[50000];
    for (int i = 0; i < t; ++i) {
        scanf("%s", s);
        int n = strlen(s);
        vector<bool> p(n + 1, false);
        p[0] = true;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < NUM_ELEMS; ++k) {
                char *elem = table[k];
                int m = strlen(elem);
                if (j + m > n) {
                    continue;
                }
                bool match = true;
                for (int h = 0; h < m; ++h) {
                    if (s[j + h] != elem[h]) {
                        match = false;
                    }
                }
                p[j + m] = p[j + m] || (p[j] && match);
            }
        }
        if (p[n]) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}
