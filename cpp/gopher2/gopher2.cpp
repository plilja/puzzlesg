#include <iostream>
#include <cmath>
#include <vector>
#include "fordfulkerson.h"

using namespace std;

typedef pair<double, double> point;

double EPS = 10e-8;

vector<point> read_points(int num)
{
    vector<point> points;
    for (int i = 0; i < num; ++i) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        points.push_back({x, y});
    }
    return points;
}

int solve(vector<point> &gophers, vector<point> &holes, int s, int v)
{
    vector<FlowEdge> edges;
    for (int i = 0; i < (int)gophers.size(); ++i) {
        auto &g = gophers[i];
        for (int j = 0; j < (int)holes.size(); ++j) {
            auto &h = holes[j];
            double d = sqrt(pow(g.first - h.first, 2) + pow(g.second - h.second, 2));
            if (d / v - EPS < s) {
                edges.push_back(FlowEdge({i, j + (int)gophers.size(), 1}));
            }
        }
    }
    vector<vector<bool>> has_edge(202, vector<bool>(202, false));
    int source = gophers.size() + holes.size();
    int sink = source + 1;
    int tmp = edges.size();
    for (int i = 0; i < tmp; ++i) {
        auto e = edges[i];
        if (!has_edge[source][e.from]) {
            edges.push_back(FlowEdge({source, e.from, 1}));
            has_edge[source][e.from] = true;
        }
        if (!has_edge[e.to][sink]) {
            edges.push_back(FlowEdge({e.to, sink, 1}));
            has_edge[e.to][sink] = true;
        }
    }
    auto flow = maxFlow(edges, gophers.size() + holes.size() + 2, source, sink);
    return gophers.size() - flow.flow;
}

int main()
{
    int n, m, s, v;
    while (4 == scanf("%d %d %d %d", &n, &m, &s, &v)) {
        vector<point> gophers = read_points(n);
        vector<point> holes = read_points(m);
        int r = solve(gophers, holes, s, v);
        printf("%d\n", r);
    }
}
