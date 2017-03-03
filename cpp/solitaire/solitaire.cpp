#include <iostream>
#include <set>
#include <map>
#include <bitset>

using namespace std;

typedef pair<int, int> pii;
typedef unsigned long long ull;

const int H = 5;
const int W = 9;
const int INF = 1000000;

pii deltas[] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

bool isValidPos(int x, int y) {
    if (y == 0 || y == H - 1) {
        return x > 2 && x < 6;
    }
    return x >= 0 && y >= 0 && x < W && y < H;
}

ull hash_pegs(set<pii> &pegs) {
    bitset<63> board(0);
    for (pii peg : pegs) {
        board[peg.second * W + peg.first] = 1;
    }
    return board.to_ulong();
}

pii solve(set<pii> &pegs, map<ull, pii> &cache) {
    ull key = hash_pegs(pegs);
    if (cache.count(key) > 0) {
        return cache[key];
    }
    int best = pegs.size();
    int moves = 0;
    set<pii> pegs_copy(pegs.begin(), pegs.end());
    for (pii peg : pegs) {
        for (int i = 0; i < 4; ++i) {
            int dx = deltas[i].first;
            int dy = deltas[i].second;
            if (isValidPos(peg.first + dx, peg.second + dy) &&
                    isValidPos(peg.first + 2*dx, peg.second + 2*dy) &&
                    pegs.count({peg.first + dx, peg.second + dy}) > 0 &&
                    pegs.count({peg.first + 2*dx, peg.second + 2*dy}) == 0
               ) {
                pegs_copy.erase(peg);
                pegs_copy.erase({peg.first + dx, peg.second + dy});
                pegs_copy.insert({peg.first + 2*dx, peg.second + 2*dy});
                pii sub = solve(pegs_copy, cache);
                pegs_copy.insert(peg);
                pegs_copy.insert({peg.first + dx, peg.second + dy});
                pegs_copy.erase({peg.first + 2*dx, peg.second + 2*dy});
                if (sub.first < best) {
                    best = sub.first;
                    moves = sub.second + 1;
                } else if (sub.first == best and sub.second + 1 < moves) {
                    moves = sub.second + 1;
                }
            }
        }
    }
    cache[key] = {best, moves};
    return {best, moves};
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        set<pii> pegs;
        for (int i = 0; i < H; ++i) {
            char s[20];
            scanf("%s", s);
            for (int j = 0; j < W; ++j) {
                if (s[j] == 'o') {
                    pegs.insert({j, i});
                }
            }
        }
        map<ull, pii> cache;
        pii ans = solve(pegs, cache);
        printf("%d %d\n", ans.first, ans.second);
    }
}
