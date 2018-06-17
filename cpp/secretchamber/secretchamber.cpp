#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool match(char *w1, char *w2, vector<vector<bool>> &translation_table) {
    int n1 = strlen(w1);
    int n2 = strlen(w2);
    if (n1 != n2) {
        return false;
    } else {
        for (int i = 0; i < n1; ++i) {
            if (!translation_table[w1[i]][w2[i]]) {
                return false;
            }
        }
        return true;
    }
}

vector<vector<bool>> create_translation_table(vector<vector<char>> &translations) {
    vector<vector<bool>> res('z' + 1, vector<bool>('z' + 1, false));
    queue<char> q;
    for (char start = 'a'; start <= 'z'; start++) {
        q.push(start);
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            if (res[start][c]) {
                continue;
            }
            res[start][c] = true;
            for (char neigh : translations[c]) {
                q.push(neigh);
            }
        }
    }
    return res;
}

int main() {
    int m, n;
    scanf("%d %d\n", &m, &n);
    vector<vector<char>> translations('z' + 1, vector<char>());
    for (int i = 0; i < m; ++i) {
        char a, b;
        scanf("%c %c\n", &a, &b);
        translations[a].push_back(b);
    }
    vector<vector<bool>> translation_table = create_translation_table(translations);
    for (int i = 0; i < n; ++i) {
        char w1[52], 
             w2[52];
        scanf("%s %s", w1, w2);
        if (match(w1, w2, translation_table)) {
            puts("yes");
        } else {
            puts("no");
        }
    }
}
