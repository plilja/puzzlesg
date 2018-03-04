#include "disjoint_set.h"
#include <vector>
#include <cassert>
#include <cstdio>

DisjointSet::DisjointSet(int size)
{
    nodes = std::vector<DisjointSetNode>(size, DisjointSetNode({NULL, 0}));
    _count = size;
}

DisjointSet::~DisjointSet()
{
}

int DisjointSet::count()
{
    return _count;
}

DisjointSetNode *DisjointSet::find(int x)
{
    assert(x >= 0 && x < nodes.size());
    DisjointSetNode *node = &nodes[x];
    while (node->parent != NULL) {
        node = node->parent;
    }
    return node;
}

void DisjointSet::merge(int x, int y)
{
    DisjointSetNode *x_root = find(x);
    DisjointSetNode *y_root = find(y);
    if (x_root == y_root) {
        return; //already in same set
    }

    if (x_root->rank < y_root->rank) {
        x_root->parent = y_root;
    } else if (x_root->rank > y_root->rank) {
        y_root->parent = x_root;
    } else {
        y_root->parent = x_root;
        x_root->rank = x_root->rank + 1;
    }
    _count--;
}

bool DisjointSet::same(int x, int y)
{
    return find(x) == find(y);
}
