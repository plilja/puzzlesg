#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <cmath>

using namespace std;

double EPS = 10e-12;

int get_or_default(const vector<int> &v, int idx, int def)
{
    if (idx < (int)v.size()) {
        return v[idx];
    } else {
        return def;
    }
}

vector<int> break_at_first_one(const shared_ptr<vector<int>> &v)
{
    vector<int> res;
    for (int a : *v) {
        if (a == 1)
            break;
        res.push_back(a);
    }
    return res;
}

bool less_than(const shared_ptr<vector<int>> &v1, const shared_ptr<vector<int>> &v2)
{
    vector<int> clean_v1 = break_at_first_one(v1);
    vector<int> clean_v2 = break_at_first_one(v2);
    bool rev = clean_v1.size() > clean_v2.size(); 

    double ypow = 1;
    double d = 1;
    int start = max(((int)clean_v1.size()) - 1, ((int)clean_v2.size()) - 1);
    for (int i = start; i >= 0; --i) {
        int x = get_or_default(rev ? clean_v2 : clean_v1, i, 1); // use the vector with the smallest number of exponents for x
        int y = get_or_default(rev ? clean_v1 : clean_v2, i, 1);
        double log_x = log(x);
        double log_y = log(y);
        double fact = (log_x / log_y) * d - 1;

        if (abs(fact) < EPS) {
            d = 1;
        } else {
            d = powl(y, ypow * fact);
        }
        if (d > 50) {
            // with the limits given in the problem statement, if we reach here d can never turn around and become less than 1
            if (rev) {
                return true;
            } else {
                return false;
            }

        }
        if (d < 0.05) {
            // with the limits given in the problem statement, if we reach here d can never turn around and become greater than 1
            if (rev) {
                return false;
            } else {
                return true;
            }

        }
        ypow = pow(y, ypow);
    }
    if (rev) {
        return d > 1 + EPS;
    } else {
        return d < 1 - EPS;
    }
}

void solve(vector<shared_ptr<vector<int>>> &nums)
{
    stable_sort(nums.begin(), nums.end(), less_than);
}

int main()
{
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


