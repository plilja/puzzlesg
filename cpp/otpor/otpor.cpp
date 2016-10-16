#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

pair<double, char *> circ(char *circuit, vector<double> &resistors);

pair<int, char *> parse_int(char *circuit) {
    char c = circuit[0];
    if (c >= '0' && c <= '9') {
        int d = c - '0';
        auto p = parse_int(circuit + 1);
        int f = (int) pow(10, (p.second - circuit) / sizeof(char) - 1);
        return {f * d + p.first, p.second};
    } else {
        return {0, circuit};
    }
}

pair<double, char *> connection(char *circuit, vector<double> &resistors, vector<double> &resistors_in_conn, bool is_serial) {
    char c = circuit[0];
    if (c == ')') {
        if (is_serial) {
            double res = 0;
            for (auto r : resistors_in_conn) {
                res += r;
            }
            return {res, circuit};
        } else {
            double den = 0;
            for (auto r : resistors_in_conn) {
                den += 1 / r;
            }
            return {1 / den, circuit};
        }
    } else if (c == 'R') {
        auto p = parse_int(circuit + 1);
        double r = resistors[p.first - 1];
        resistors_in_conn.push_back(r);
        return connection(p.second, resistors, resistors_in_conn, is_serial);
    } else if (c == '|') {
        return connection(circuit + 1, resistors, resistors_in_conn, false);
    } else if (c == '-') {
        return connection(circuit + 1, resistors, resistors_in_conn, true);
    } else if (c == '(') {
        auto p = circ(circuit, resistors);
        resistors_in_conn.push_back(p.first);
        return connection(p.second, resistors, resistors_in_conn, is_serial);
    } else {
        assert(false); // Illegal state
    }
}

pair<double, char *> circ(char *circuit, vector<double> &resistors) {
    char c1 = circuit[0];
    assert(c1 == '(');

    vector<double> v;
    auto p = connection(circuit + 1, resistors, v, false);

    char c2 = p.second[0];
    assert(c2 == ')');

    return {p.first, p.second + 1};
}

int main() {
    int n;
    scanf("%d", &n);
    vector<double> resistors(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &resistors[i]);
    }
    char circuit[100003];
    scanf("%s", circuit);
    auto ans = circ(circuit, resistors);
    printf("%.5lf\n", ans.first);
}