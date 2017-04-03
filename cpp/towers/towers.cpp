#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <cmath>
#include <limits>
#include <cassert>
#include <cstring>

using namespace std;

double EPS = 10e-12;
double INF = numeric_limits<double>::infinity();

int get_or_default(const shared_ptr<vector<int>> &v, int v_end, int idx, int def) {
    if (idx < v_end) {
        return (*v)[idx];
    } else {
        return def;
    }
}

int first_one(const shared_ptr<vector<int>> &v) {
    vector<int> res;
    for (int i = 0; i < v->size(); ++i) {
        if ((*v)[i] == 1) {
            return i;
        }
    }
    return v->size();
}

double quotient(const shared_ptr<vector<int>> &v1, int v1_end, const shared_ptr<vector<int>> &v2, int v2_end) {
    assert(v1_end <= v2_end);
    double ypow = 1;
    double d = 1;
    int start = v2_end - 1;
    for (int i = start; i >= 0; --i) {
        double x = get_or_default(v1, v1_end, i, 1); // use the vector with the smallest number of exponents for x
        double y = get_or_default(v2, v2_end, i, 1);
        double fact = d * log(x) / log(y) - 1;
        if (abs(fact) < EPS) {
            d = 1;
        } else {
            d = pow(y, ypow * fact);
        }
        if (d > 50) {
            // with the limits given in the problem statement, if we reach here d can never turn around and become less than 1
            return INF;
        }
        if (d < 0.05) {
            // with the limits given in the problem statement, if we reach here d can never turn around and become greater than 1
            return 0;
        }
        ypow = pow(y, ypow);
    }
    return d;
}

bool less_than(const shared_ptr<vector<int>> &v1, const shared_ptr<vector<int>> &v2) {
    int v1_one = first_one(v1);
    int v2_one = first_one(v2);
    if (v1_one < v2_one) {
        return quotient(v1, v1_one, v2, v2_one) < 1 - EPS;
    } else {
        return quotient(v2, v2_one, v1, v1_one) > 1 + EPS;
    }
}

void solve(vector<shared_ptr<vector<int>>> &nums) {
    stable_sort(nums.begin(), nums.end(), less_than);
}

int main() {
    int m;
    int c = 1;
    while (1 == scanf("%d\n", &m)) {
        vector<shared_ptr<vector<int>>> nums;
        for (int i = 0; i < m; ++i) {
            nums.push_back(make_shared<vector<int>>());
            char line[2000];
            fgets(line, 2000, stdin);
            char *p = strtok(line, "^");
            while (p != NULL) {
                nums[i]->push_back(stoi(p));
                p = strtok(NULL, "^");
            }
        }
        solve(nums);
        printf("Case %d:\n", c);
        for (auto &v : nums) {
            printf("%d", (*v)[0]);
            for (int i = 1; i < (int)v->size(); ++i) {
                printf("^%d", (*v)[i]);
            }
            puts("");
        }
        c++;
    }
}
