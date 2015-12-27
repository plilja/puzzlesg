#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

const ull INF = 200000L * 500000L;
const int MAX_DICT_W_SIZE = 10;

int char_to_int[] = {
    2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5,
    6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9
};

ull checksum(string &w)
{
    ull r = 0;
    for (char c : w) {
        r *= 10;
        r += char_to_int[c - 'a'];
    }
    return r;
}

void solve(string &w, unordered_map<string, int> &dist)
{
    vector <ull> m(w.size(), INF);
    vector <pair<int, int>> next(w.size());
    for (int i = (int)w.size() - 1; i >= 0; --i) {
        int lim = min(MAX_DICT_W_SIZE, (int)w.size() - i);
        string sub = "";
        for (int j = 0; j < lim; ++j) {
            sub += w[i + j];
            ull d = sub.size();
            if (i + j + 1 < (int) w.size()) {
                d += m[i + j + 1];
                d += 1; //need to press R key
            }
            if (d >= m[i]) {
                continue;
            }

            auto it = dist.find(sub);
            if (it == dist.end()) {
                continue;
            }
            d += abs(it->second);

            if (d < m[i]) {
                m[i] = d;
                next[i] = {i + j + 1, it->second};
            }
        }
    }

    //walk next pointers to get solution
    int i = 0;
    while (i < (int) w.size()) {
        auto n = next[i];
        for (int j = i; j < n.first; ++j) {
            char c = w[j];
            printf("%d", char_to_int[c - 'a']);
        }
        int press_up_or_down = n.second;
        if (press_up_or_down != 0) {
            if (press_up_or_down < 0) {
                printf("D(%d)", -press_up_or_down);
            } else {
                printf("U(%d)", press_up_or_down);
            }
        }
        if (n.first < (int) w.size()) {
            printf("R");
        }
        i = n.first;
    }
    puts("");
}

int main()
{
    int n;
    scanf("%d\n", &n);
    vector<pair<pair<ull, int>, string>> dict;
    for (int i = 0; i < n; ++i) {
        char w[13];
        scanf("%s\n", w);
        string word(w);
        dict.push_back({{checksum(word), i}, word});
    }
    sort(dict.begin(), dict.end());
    unordered_map<string, int> dist;
    int j = 0;
    while (j < (int)dict.size()) {
        ull start = dict[j].first.first;
        int end = j;
        while (end < (int)dict.size() && dict[end].first.first == start) {
            end++;
        }
        int group_size = end - j;
        for (int i = j; i < end; ++i) {
            int keys_up = i - j;
            int keys_down = group_size - i + j;
            string &w = dict[i].second;
            if (keys_down <= keys_up) {
                dist[w] = -keys_down;
            } else {
                dist[w] = keys_up;
            }
        }
        j = end;
    }
    int q;
    scanf("%d\n", &q);
    for (int i = 0; i < q; ++i) {
        char w[500004];
        scanf("%s\n", w);
        string word(w);
        solve(word, dist);
    }
}
