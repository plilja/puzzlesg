#pragma once

#include <vector>

struct SpanningTree {
    bool valid;
    std::vector<std::pair<int, int>> edges;
    double total_cost;
};

/*
 * An implementation of prims algorithm for finding the minimal spanning tree
 * i an undirected graph. The weights of the edges may be both negativa and positive. 
 * 
 * The algorithm runs in time O( |E|+|V|)*log(|V|).
 * 
 * Parameters:
 * edges : A list of the edges in the graph allong with their weights. Note that nodes
 * 			are numbered from 0..nr_of_nodes - 1. Also note that edges are undirected.  
 * nr_of_nodes: The number of nodes in the graph
 *
 * Return: A spanning tree. If no spanning tree exists the valid flag will be set to false.
 */
SpanningTree prim(std::vector<std::pair<std::pair<int, int>, double> > &edges, int nr_of_nodes);

