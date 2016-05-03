#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef pair<int, int> pii;

const int DECIMAL = 1;
const int BINARY = 0;
const int NEITHER = 2;

int main() {
    int r, c;
    scanf("%d %d\n", &r, &c);
    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        char line[1010];
        fgets(line, 1010, stdin);
        for (int j = 0; j < c; ++j) {
            grid[i][j] = (int) (line[j] - '0');
        }
    }
    int n;
    scanf("%d", &n);
    vector<pair<pii, pii>> queries;
    map<pii, set<int>> pointToQuery;
    for (int i = 0; i < n; ++i) {
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

        //make zero indexed
        r1--;
        c1--;
        r2--;
        c2--;
        queries.push_back({{r1, c1},
                           {r2, c2}});
        pointToQuery[{r1, c1}].insert(i);
        pointToQuery[{r2, c2}].insert(i);
    }
    vector<int> answers(n, -1);
    for (int k = 0; k < n; ++k) {
        if (answers[k] != -1) {
            continue;
        }
        auto q = queries[k];
        // bfs
        queue<pii> _queue;
        vector<vector<bool>> v(r, vector<bool>(c, false));
        _queue.push({q.first.first, q.first.second});
        int start = grid[q.first.first][q.first.second];
        set<int> canBeAnswered;
        while (!_queue.empty()) {
            auto p = _queue.front();
            _queue.pop();
            int y = p.first;
            int x = p.second;
            if (y < 0 || y >= r || x < 0 || x >= c || v[y][x] || grid[y][x] != start) {
                continue;
            }
            auto it = pointToQuery.find({y, x});
            if (it != pointToQuery.end()) {
                for (int q : it->second) {
                    canBeAnswered.insert(q);
                }
            }
            v[y][x] = true;
            _queue.push({y + 1, x});
            _queue.push({y - 1, x});
            _queue.push({y, x + 1});
            _queue.push({y, x - 1});
        }
        for (int q : canBeAnswered) {
            int r1 = queries[q].first.first;
            int c1 = queries[q].first.second;
            int r2 = queries[q].second.first;
            int c2 = queries[q].second.second;
            if (v[r1][c1]) {
                if (v[r2][c2]) {
                    if (start == 1) {
                        answers[q] = DECIMAL;
                    } else {
                        answers[q] = BINARY;
                    }
                } else {
                    answers[q] = NEITHER;
                }
            } else {
                answers[q] = NEITHER;
            }
        }
    }
    for (int ans : answers) {
        if (ans == DECIMAL) {
            puts("decimal");
        } else if (ans == BINARY) {
            puts("binary");
        } else {
            puts("neither");
        }
    }
}

