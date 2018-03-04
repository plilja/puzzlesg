#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cassert>
#include "disjoint_set.h"
#include "indexmap.h"

using namespace std;

string rhyme_part(string &s) {
    int len = min(3, (int) s.length());
    return s.substr(s.size() - len, len);
}

class Solver {
public:
    Solver(int _n) : ds(2*_n), n(_n) {
    }

    void process_sub(int idx, string &rhyme, int sub_len) {
        if (rhyme.size() > sub_len) {
            auto sub = rhyme.substr(rhyme.size() - sub_len, sub_len);
            if (rhymes_with.count(sub) > 0) {
                ds.merge(idx, rhymes_with[sub]);
            } else {
                word_endings[sub].push_back(idx);
            }
        } 
        if (rhyme.size() == sub_len) {
            for (int w : word_endings[rhyme]) {
                ds.merge(idx, w);
            }
        }
    }

    void new_word(string &word, int idx) {
        auto rhyme = rhyme_part(word);
        if (rhymes_with.count(rhyme) > 0) {
            ds.merge(idx, rhymes_with[rhyme]);
        } else {
            rhymes_with[rhyme] = idx;
            process_sub(idx, rhyme, 2);
            process_sub(idx, rhyme, 1);
        }
    }

    bool solve() {
        for (int i = 0; i < n; ++i) {
            string a, rel, b;
            cin >> a >> rel >> b;
            int a_idx = word_idx.getIndex(a);
            int b_idx = word_idx.getIndex(b);
            new_word(a, a_idx); 
            new_word(b, b_idx); 
            if (rel == "is") {
                ds.merge(a_idx, b_idx);
            } else {
                assert(rel == "not");
                not_equal.push_back({a_idx, b_idx});
            }
        }
        bool consistent = true;
        for (auto p : not_equal) {
            if (ds.same(p.first, p.second)) {
                consistent = false;
                break;
            }
        }
        return consistent;
    }

    int n;
    DisjointSet ds;
    Indexmap<string> word_idx;
    map<string, int> rhymes_with;
    map<string, vector<int>> word_endings;
    vector<pair<int, int>> not_equal;
};

int main() {
    int n;
    cin >> n;
    Solver s(n);
    if (s.solve()) {
        puts("yes");
    } else {
        puts("wait what?");
    }
}
