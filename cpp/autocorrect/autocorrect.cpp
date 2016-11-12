#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Trie {
public:
    Trie(string *_most_common_string) :
            next(26, NULL),
            most_common_string(_most_common_string) {
    }

    ~Trie() {
        for (Trie *t : next) {
            if (t != NULL) {
                delete t;
            }
        }
    }

    void insert(string *s) {
        insert(s, 0);
    }

    Trie *lookup(char c) {
        return next[c - 'a'];
    }

    string *most_common_word() {
        return most_common_string;
    }

private:
    void insert(string *s, int i) {
        if (i >= s->size()) {
            return;
        }
        int c = (*s)[i] - 'a';
        if (next[c] == NULL) {
            next[c] = new Trie(s);
        }
        next[c]->insert(s, i + 1);
    }

    vector<Trie *> next;
    string *most_common_string;
};

int solve(Trie &trie, string &q) {
    int ans = (int) q.size();
    Trie *t = &trie;
    string *prev_most_common = NULL;
    int prev_most_common_start = 0;
    int running_cost = 0;
    for (int j = 1; j <= q.size(); ++j) {
        t = t->lookup(q[j - 1]);
        if (t == NULL) {
            break;
        }
        string *most_common = t->most_common_word();
        if (most_common != prev_most_common) {
            if (prev_most_common != NULL) {
                running_cost += min(j - prev_most_common_start, (int) prev_most_common->size() - j + 3);
            } else {
                running_cost += j - prev_most_common_start;
            }
            prev_most_common_start = j;
        }
        prev_most_common = most_common;
        ans = min(ans, (int) (most_common->size() + q.size() - 2 * j + running_cost + 1));
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    string *dict = new string[n];
    Trie trie((string *) -1);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        dict[i] = s;
        trie.insert(&dict[i]);
    }
    for (int i = 0; i < m; ++i) {
        string q;
        cin >> q;
        int ans = solve(trie, q);
        cout << ans << endl;
    }
    delete[] dict;
}
