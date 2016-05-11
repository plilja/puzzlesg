#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cassert>
#include "avltree.cpp"

using namespace std;

const int ALPH_SIZE = 'z' - 'a' + 1;

class Trie {
public:
    Trie() {
        transitions = new Trie*[ALPH_SIZE];
        for (int i = 0; i < ALPH_SIZE; ++i) {
            transitions[i] = 0;
        }
        count = 0;
    }

    Trie *addTransition(char to) {
        int idx = to - 'a';
        if (transitions[idx] == 0) {
            transitions[idx] = new Trie();
        }
        return transitions[idx];
    }

    Trie *getTransition(char to) {
        int idx = to - 'a';
        return transitions[idx];
    }

    ~Trie() {
        for (int i = 0; i < ALPH_SIZE; ++i) {
            if (transitions[i] != 0)
                delete transitions[i];
        }
        delete transitions;
    }

    int numLarger(int n) {
        for (int i : sizeQueue) {
            sizes.insert(i);
        }
        sizeQueue.clear();
        return count - sizes.numSmaller(n);
    }

    void addSize(int size) {
        sizeQueue.push_back(size);
    }

    Trie** transitions;
    int count;
    AVLTree sizes;
    vector<int> sizeQueue;
};


const int LT = -1;
const int EQ = 0;
const int GT = 1;


int substrcmp(const string &a, const string &b) {
    int t = min(a.size(), b.size());
    for (int i = 0; i < t; ++i) {
        if (a[i] < b[i]) {
            return LT;
        } else if (b[i] < a[i]) {
            return GT;
        }
    }
    return EQ;
}

int mystrcmp(const string &a, const string &b) {
    int t = substrcmp(a, b);
    if (t != EQ) {
        return t;
    }
    if (a.size() < b.size()) {
        return GT;
    } else if (b.size() < a.size()) {
        return LT;
    } else {
        return EQ;
    }
}

int bin_search_start(vector<string> &v, string &w, int l, int r) {
    while (l < r) {
        int m = l + (r - l) / 2;

        int t = substrcmp(v[m], w);
        if (t == LT) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

int bin_search_end(vector<string> &v, string &w, int l, int r) {
    while (l < r) {
        int m = l + (r - l) / 2;
        int t = mystrcmp(v[m], w);
        if (t == LT || t == EQ) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return r;
}


bool cmp(const string &a, const string &b) {
    return mystrcmp(a, b) == LT;
}

Trie *walkFromRight(Trie *t, string &s) {
    for (int k = (int) s.size() - 1; k >= 0 && t != 0; --k) {
        char c = s[k];
        t = t->getTransition(c);
    }
    return t;
}

void insertFromRight(Trie *t, string &w) {
    for (int k = w.size() - 1; k >= 0; --k) {
        char c = w[k];
        t->count++;
        t->addSize(k + 1);
        t = t->addTransition(c);
    }
    t->count++;
    t->addSize(0);
}

int main() {

    int n, q;
    scanf("%d %d\n", &n, &q);
    char str[400005];
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        words[i] = str;
    }

    vector<pair<string, string>> patterns(q);
    for (int i = 0; i < q; ++i) {
        scanf("%s", str);
        string pattern = str;
        for (int j = 0; j < (int) pattern.size(); ++j) {
            if (pattern[j] == '*') {
                string left = pattern.substr(0, j);
                string right = pattern.substr(j + 1, pattern.size() - j - 1);
                patterns[i] = {left, right};
                break;
            }
        }
    }

    sort(words.begin(), words.end(), cmp);

    Trie trie;

    vector<pair<int, int>> beginnings;
    vector<pair<int, int>> endings;
    for (int i = 0; i < q; ++i) {
        auto &p = patterns[i];
        auto &left = p.first;

        int begin = bin_search_start(words, left, 0, words.size());
        int end = bin_search_end(words, left, 0, words.size());
        beginnings.push_back({begin, i});
        endings.push_back({end, i});
    }
    sort(beginnings.begin(), beginnings.end());
    sort(endings.begin(), endings.end());

    vector<int> answers(q, 0);
    int a = 0;
    int b = 0;
    for (int i = 0; i < n; ++i) {
        auto &w = words[i];
        while (a < q && i == beginnings[a].first) {
            int p = beginnings[a].second;
            auto &left = patterns[p].first;
            auto &right = patterns[p].second;

            Trie *t = walkFromRight(&trie, right);
            if (t != 0) {
                answers[p] -= t->numLarger(left.size());
            }

            a++;
        }
        while (b < q && i == endings[b].first) {
            int p = endings[b].second;
            auto &left = patterns[p].first;
            auto &right = patterns[p].second;

            Trie *t = walkFromRight(&trie, right);
            if (t != 0) {
                answers[p] += t->numLarger(left.size());
            }

            b++;
        }
        insertFromRight(&trie, w);
    }

    while (a < q) {
        int p = beginnings[a].second;
        auto &left = patterns[p].first;
        auto &right = patterns[p].second;

        Trie *t = walkFromRight(&trie, right);
        if (t != 0) {
            answers[p] -= t->numLarger(left.size());
        }
        a++;
    }

    while (b < q) {
        int p = endings[b].second;
        auto &left = patterns[p].first;
        auto &right = patterns[p].second;

        Trie *t = walkFromRight(&trie, right);
        if (t != 0) {
            answers[p] += t->numLarger(left.size());
        }

        b++;
    }

    for (int a : answers) {
        printf("%d\n", a);
    }
}


