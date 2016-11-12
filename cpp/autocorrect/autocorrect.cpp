#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Trie {
public:
    Trie(int _most_common_string_id) :
            next(26, NULL),
            most_common_string_id(_most_common_string_id) {
    }

    ~Trie() {
        for (Trie *t : next) {
            if (t != NULL) {
                delete t;
            }
        }
    }

    void insert(string &s, int string_id) {
        insert(s, string_id, 0);
    }

    Trie *lookup(char c) {
        return next[c - 'a'];
    }

    int most_common_word() {
        return most_common_string_id;
    }

private:
    void insert(string &s, int string_id, int i) {
        if (i >= s.size()) {
            return;
        }
        int c = s[i] - 'a';
        if (next[c] == NULL) {
            next[c] = new Trie(string_id);
        }
        next[c]->insert(s, string_id, i + 1);
    }

    vector<Trie *> next;
    int most_common_string_id;
};

int solve(Trie &trie, vector<string> &dict, string &q) {
    int ans = (int) q.size();
    Trie *t = &trie;
    int prev_most_common = -1;
    int prev_most_common_start = 0;
    int running_cost = 0;
    for (int j = 1; j <= q.size(); ++j) {
        t = t->lookup(q[j - 1]);
        if (t == NULL) {
            break;
        }
        int most_common = t->most_common_word();
        string &s = dict[most_common];
        if (most_common != prev_most_common) {
            if (prev_most_common >= 0) {
                string &ps = dict[prev_most_common];
                running_cost += min(j - prev_most_common_start, (int) ps.size() - j + 3);
            } else {
                running_cost += j - prev_most_common_start;
            }
            prev_most_common_start = j;
        }
        prev_most_common = most_common;
        ans = min(ans, (int) (s.size() + q.size() - 2 * j + running_cost + 1));
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> dict(n);
    Trie trie(-1);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        trie.insert(s, i);
        dict[i] = s;
    }
    for (int i = 0; i < m; ++i) {
        string q;
        cin >> q;
        int ans = solve(trie, dict, q);
        cout << ans << endl;
    }
}
