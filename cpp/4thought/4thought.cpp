#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

char ops[] = {'-', '+', '/', '*'};

int eval(vector<char> &exp, int left, int i) {
    if (i == 3)
        return left;
    if (exp[i] == '+')
        return left + eval(exp, 4, i + 1);
    else if (exp[i] == '-')
        return left + eval(exp, -4, i + 1);
    else if (exp[i] == '*')
        return eval(exp, left * 4, i + 1);
    else {
        assert (exp[i] == '/');
        return eval(exp, left / 4, i + 1);
    }
}

bool solve(int n, vector<char> &r, int i)
{
    for (int j = 0; j < 4; ++j)
    {
        char op = ops[j];
        r[i] = op;
        if (i == 3 && eval(r, 4, 0) == n)
            return true;
        else if (i < 3 && solve(n, r, i + 1))
            return true;
    }
    return false;

}

int main()
{
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        int n;
        scanf("%d", &n);
        vector<char> r(4);
        bool sol_exists = solve(n, r, 0);
        if (sol_exists)
            printf("4 %c 4 %c 4 %c 4 = %d\n", r[0], r[1], r[2], n);
        else 
            puts("no solution");
    }
}
