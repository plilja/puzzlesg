#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

void set(vector<bitset<10>> &allowed, int y, int x, int val) {
    for (int k = 0; k < 9; ++k) {
        allowed[9 * k + x][val] = false;
        allowed[9 * y + k][val] = false;
    }
    for (int l = 0; l < 3; ++l) {
        for (int k = 0; k < 3; ++k) {
            int w = 3 * (y / 3);
            int z = 3 * (x / 3);
            allowed[9 * (w + l) + z + k][val] = false;
        }
    }
    auto b = bitset<10>(0);
    b[val] = true;
    allowed[9 * y + x] = b;
}

int applySimple(vector<vector<int>> &s, vector<bitset<10>> &allowed) {
    int res = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (s[i][j] != 0) {
                continue;
            }
            auto al = allowed[9 * i + j];
            if (al.to_ulong() == 0) {
                return -1;
            }
            if (al.count() == 1) {
                int p;
                for (int h = 1; h <= 9; ++h) {
                    if (allowed[9 * i + j][h]) {
                        p = h;
                        break;
                    }
                }
                s[i][j] = p;
                set(allowed, i, j, p);
                res++;
            }
        }
    }
    for (int h = 1; h <= 9; ++h) {
        for (int i = 0; i < 9; ++i) {
            int c = 0;
            int p;
            for (int j = 0; j < 9 && c < 2; ++j) {
                if (allowed[9 * i + j][h]) {
                    c++;
                    p = j;
                }
            }
            if (c == 0) {
                return -1;
            } else if (c == 1) {
                if (s[i][p] == 0) {
                    s[i][p] = h;
                    set(allowed, i, p, h);
                    res++;
                }
            }
        }
    }
    for (int h = 1; h <= 9; ++h) {
        for (int j = 0; j < 9; ++j) {
            int c = 0;
            int p;
            for (int i = 0; i < 9 && c < 2; ++i) {
                if (allowed[9 * i + j][h]) {
                    c++;
                    p = i;
                }
            }
            if (c == 0) {
                return -1;
            } else if (c == 1) {
                if (s[p][j] == 0) {
                    s[p][j] = h;
                    set(allowed, p, j, h);
                    res++;
                }
            }
        }
    }
    for (int h = 1; h <= 9; ++h) {
        for (int w = 0; w < 3; ++w) {
            for (int z = 0; z < 3; ++z) {
                int c = 0;
                int px, py;
                for (int i = 0; i < 3 && c < 2; ++i) {
                    for (int j = 0; j < 3 && c < 2; ++j) {
                        if (allowed[9 * (3 * w + i) + 3 * z + j][h]) {
                            c++;
                            py = 3 * w + i;
                            px = 3 * z + j;
                        }
                    }
                }
                if (c == 0) {
                    return -1;
                } else if (c == 1) {
                    if (s[py][px] == 0) {
                        s[py][px] = h;
                        set(allowed, py, px, h);
                        res++;
                    }
                }

            }
        }

    }
    return res;
}

int solve(vector<vector<int>> s, vector<bitset<10>> &allowed, int y, int x, vector<vector<int>> &sol) {
    if (x == 9) {
        return solve(s, allowed, y + 1, 0, sol);
    }
    if (y == 9) {
        sol = vector<vector<int>>(s);
        return 1;
    }
    while (true) {
        int simple = applySimple(s, allowed);
        if (simple < 0) {
            return 0;
        }
        if (simple == 0) {
            break;
        }
    }
    auto al = allowed[9 * y + x];
    if (al.to_ullong() == 0) {
        return 0;
    } else if (s[y][x] != 0) {
        return solve(s, allowed, y, x + 1, sol);
    } else {
        int sol_found = 0;
        for (int i = 1; i <= 9; ++i) {
            if (al[i]) {
                s[y][x] = i;
                vector<bitset<10>> newAllowed(allowed);
                set(newAllowed, y, x, i);
                sol_found += solve(s, newAllowed, y, x + 1, sol);
                if (sol_found > 1) {
                    return sol_found;
                }
            }
        }
        return sol_found;
    }
}

int solve(vector<vector<int>> &s, vector<vector<int>> &sol) {
    vector<bitset<10>> allowed(81, bitset<10>(0b1111111110));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int val = s[i][j];
            if (val == 0) {
                continue;
            }
            if (!allowed[9 * i + j][val]) {
                return 0;
            }
            set(allowed, i, j, val);
        }
    }
    return solve(s, allowed, 0, 0, sol);
}

int main() {
    bool first = true;
    while (true) {
        vector<vector<int>> s(9, vector<int>(9));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (1 != scanf("%d", &s[i][j])) {
                    return 0;
                }
            }
        }
        vector<vector<int>> sol;
        auto ans = solve(s, sol);
        if (!first) {
            puts("");
        }
        first = false;
        if (ans == 1) {
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    if (j == 0) {
                        printf("%d", sol[i][j]);
                    } else {
                        printf(" %d", sol[i][j]);
                    }
                }
                puts("");
            }
        } else if (ans > 1) {
            puts("Non-unique");
        } else {
            puts("Find another job");
        }
        scanf("\n");
    }
}
