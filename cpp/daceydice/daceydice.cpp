#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef vector<vector<char>> Graph;

struct Pos {
    int x, y, bottom, top, left, right, down, up;

    bool operator<(const Pos &p) const {
        if (x != p.x) {
            return x < p.x;
        }
        if (y != p.y) {
            return y < p.y;
        }
        if (bottom != p.bottom) {
            return bottom < p.bottom;
        }
        if (left != p.left) {
            return left < p.left;
        }
        return false; // they are equal
    }
};

bool canReachHome(Graph &g, int n, Pos start) {
    queue<Pos> q;
    q.push(start);
    set<Pos> v;

    while (!q.empty()) {
        Pos p = q.front();
        q.pop();
        if (v.count(p) > 0) {
            continue;
        }
        if (g[p.y][p.x] == 'H' && p.bottom == 5) {
            return true;
        }
        v.insert(p);

        if (p.x > 0 && g[p.y][p.x - 1] != '*') {
            q.push(Pos({p.x - 1, p.y, p.left, p.right, p.top, p.bottom, p.down, p.up}));
        }
        if (p.x + 1 < n && g[p.y][p.x + 1] != '*') {
            q.push(Pos({p.x + 1, p.y, p.right, p.left, p.bottom, p.top, p.down, p.up}));
        }
        if (p.y + 1 < n && g[p.y + 1][p.x] != '*') {
            q.push(Pos({p.x, p.y + 1, p.down, p.up, p.left, p.right, p.top, p.bottom}));
        }
        if (p.y > 0 && g[p.y - 1][p.x] != '*') {
            q.push(Pos({p.x, p.y - 1, p.up, p.down, p.left, p.right, p.bottom, p.top}));
        }
    }
    return false;
}

bool solve(Graph &g, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] == 'S') {
                return canReachHome(g, n, Pos({j, i, 6, 1, 5, 2, 3, 4}));
            }
        }
    }
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        Graph g(n, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            char s[23];
            scanf("%s", s);
            for (int j = 0; j < n; ++j) {
                g[i][j] = s[j];
            }
        }
        if (solve(g, n)) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
}
