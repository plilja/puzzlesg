#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

vector<bool> single(bool val)
{
    vector<bool> r;
    r.push_back(val);
    return r;
}

vector<bool> both(bool val1, bool val2)
{
    vector<bool> r;
    r.push_back(val1);
    r.push_back(val2);
    return r;
}

bool in(vector<bool> &vals, bool val)
{
    for (auto b : vals) {
        if (b == val)
            return true;
    }
    return false;
}

vector<bool> _and(vector<bool> &a, vector<bool> &b)
{
    vector<bool> r;
    if (in(a, true) && in(b, true))
        r.push_back(true);
    if (in(a, false) || in(b, false))
        r.push_back(false);
    return r;
}

vector<bool> _or(vector<bool> &a, vector<bool> &b)
{
    vector<bool> r;
    if (in(a, true) || in(b, true))
        r.push_back(true);
    if (in(a, false) && in(b, false))
        r.push_back(false);
    return r;
}

vector<bool> _not(vector<bool> &a)
{
    vector<bool> r;
    for (bool b : a)
        r.push_back(!b);
    return r;
}

vector<bool> implies(vector<bool> &a, vector<bool> &b)
{
    vector<bool> r;
    if (in(a, true) && in(b, false))
        r.push_back(false);
    if (in(a, false) || in(b, true))
        r.push_back(true);
    return r;
}

vector<bool> eq(vector<bool> &a, vector<bool> &b)
{
    vector<bool> r;
    if (a.size() == 2 || b.size() == 2) {
        return both(true, false);
    } else {
        return single(a[0] == b[0]);
    }
}

pair<vector<bool>, int> eval(string &expr, vector<bool> vars, int i)
{
    char c = expr[i];
    if (c == 'K') {
        auto a = eval(expr, vars, i + 1);
        auto b = eval(expr, vars, a.second + 1);
        return {_and(a.first, b.first), b.second};
    } else if (c == 'A') {
        auto a = eval(expr, vars, i + 1);
        auto b = eval(expr, vars, a.second + 1);
        return {_or(a.first, b.first), b.second};
    } else if (c == 'N') {
        auto a = eval(expr, vars, i + 1);
        return {_not(a.first), a.second};
    } else if (c == 'C') {
        auto a = eval(expr, vars, i + 1);
        auto b = eval(expr, vars, a.second + 1);
        return {implies(a.first, b.first), b.second};
    } else if (c == 'E') {
        auto a = eval(expr, vars, i + 1);
        auto b = eval(expr, vars, a.second + 1);
        return {eq(a.first, b.first), b.second};
    } else {
        return {single(vars[c - 'a']), i};
    }
}

bool tautology(string &expr)
{
    vector<bool> vars(27);
    for (int i = 0; i <= 31; ++i) {
        bitset<5> b(i);
        vars['p' - 'a'] = b[0];
        vars['q' - 'a'] = b[1];
        vars['r' - 'a'] = b[2];
        vars['s' - 'a'] = b[3];
        vars['t' - 'a'] = b[4];
        auto r = eval(expr, vars, 0);
        if (in(r.first, false)) {
            return false;
        }
    }
    return true;
}

int main()
{
    while (true) {
        string expr;
        cin >> expr;
        if (expr == "0")
            break;
        if (tautology(expr))
            cout << "tautology" << endl;
        else
            cout << "not" << endl;
    }

}
