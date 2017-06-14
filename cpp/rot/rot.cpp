#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<vector<char>> rotate90(vector<vector<char>> table) {
    vector<vector<char>> result(table[0].size(), vector<char>(table.size()));
    for (int i = 0; i < table.size(); ++i) {
        for (int j = 0; j < table[i].size(); ++j) {
            result[j][table.size() - i - 1] = table[i][j];
        }
    }
    return result;
}

vector<vector<char>> rotate45(vector<vector<char>> table) {
    int dim = table.size() + table[0].size() - 1;
    vector<vector<char>> result(dim, vector<char>(dim, ' '));
    int offset = table.size() - 1;
    for (int i = 0; i < table.size(); ++i) {
        for (int j = 0; j < table[i].size(); ++j) {
            result[i + j][offset + j] = table[i][j];
        }
        offset -= 1;
    }
    return result;
}

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);
    vector<vector<char>> table(r, vector<char>(c));
    for (int i = 0; i < r; ++i) {
        char s[13];
        scanf("%s", s);
        for (int j = 0; j < c; ++j) {
            table[i][j] = s[j];
        }
    }
    int k;
    scanf("%d", &k);
    while (k >= 90) {
        table = rotate90(table);
        k -= 90;
    }
    assert(k == 0 || k == 45);
    if (k == 45) {
        table = rotate45(table);
        k -= 45;
    }
    for (int i = 0; i < table.size(); ++i) {
        int rightmostNonSpace = table[i].size() - 1;
        for (; rightmostNonSpace >= 0; --rightmostNonSpace) {
            if (table[i][rightmostNonSpace] != ' ') {
                break;
            }
        }
        for (int j = 0; j <= rightmostNonSpace; ++j) {
            printf("%c", table[i][j]);
        }
        printf("\n");
    }
}
