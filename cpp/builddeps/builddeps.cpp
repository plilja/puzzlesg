#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <limits>
#include <cassert>
#include <queue>
#include <sstream>
#include "indexmap.h"

using namespace std;

bool visit(vector<vector<int>> &graph, int v, vector<bool> &temp_marker, set<int> &unvisited, vector<int> &result) {
    if (unvisited.count(v) == 0) {
        return true;
    } else if (temp_marker[v]) {
        return false;
    } else {
        temp_marker[v] = true;
        for (int neighbour : graph[v]) {
            visit(graph, neighbour, temp_marker, unvisited, result);
        }
        unvisited.erase(v);
        result.push_back(v);
        return true;
    }
}

vector<int> topological_sort(vector<vector<int>> &graph, int n) {
    set<int> unvisited;
    for (int i = 0; i < n; ++i) {
        unvisited.insert(i);
    }
    vector<int> result;
    vector<bool> temp_marker(n, false);
    while (!unvisited.empty()) {
        int v = *unvisited.begin();
        bool b = visit(graph, v, temp_marker, unvisited, result);
        assert(b);
    }
    return result;
}

vector<bool> bfs(vector<vector<int>> &graph, int n, int start) {
    queue<int> q;
    q.push(start);
    vector<bool> visited(n, false);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (visited[v]) {
            continue;
        }
        visited[v] = true;
        for (int neighbour : graph[v]) {
            q.push(neighbour);
        }
    }
    return visited;;
}

template <typename CharType, typename CharTraits>
std::basic_istream <CharType, CharTraits> &
endl(std::basic_istream <CharType, CharTraits> &ins) {
    return ins.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
}

int main()
{
    int n;
    cin >> n >> endl;
    Indexmap<string> indexmap;
    vector<vector<int>> graph(n);
    vector<vector<int>> reverse_graph(n);
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        istringstream ss(line);
        string f;
        ss >> f;
        f = f.substr(0, f.size() - 1);
        int curr_file = indexmap.getIndex(f);
        string dep;
        while (ss >> dep) {
            int idx = indexmap.getIndex(dep);
            graph[curr_file].push_back(idx);
            reverse_graph[idx].push_back(curr_file);
        }
    }
    string recompile;
    cin >> recompile;
    int v = indexmap.getIndex(recompile);
    vector<int> order = topological_sort(graph, n);
    vector<bool> needs_recompile = bfs(reverse_graph, n, v);
    for (int d : order) {
        if (needs_recompile[d]) {
            cout << indexmap.getObject(d) << endl;
        }
    }
}
