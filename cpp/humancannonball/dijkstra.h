#pragma once

#include <vector>

class Dijkstra
{
public:
    /*
    * Parameters:
     * edges: A list of directed edges and the cost of travelling along that edge. The indices must be in the
     * 			range 0<= index <=nr_of_nodes - 1
     * source: The index of the source nodes.
     */
    Dijkstra(std::size_t nr_of_nodes, const std::vector <std::pair<std::pair<int, int>, double>> &edges, int source);

    /*
     * Get a path, if it exists, between the source and some node.
     *
     * Returns:
     * A list of node indexes describing a path between the source and the goal. If
     * a path between the nodes doesn't exist the list will be empty. If The goal node
     * is the same as the source node, the list will simply contain this node.
     */
    std::vector<int> getPath(int goal);

    /*
     * Get the distance between the source and a goal node.
     *
     * Returns:
     * A double describing the minimum cost of a path between the source and thee goal node.
     * If a path doesn't exist this integer will be -1.
     */
    double distance(int goal);

private:

    void construct();

    std::vector<double> dist;
    int source;
    int nr_of_nodes;
    std::vector <std::vector<std::pair<int, double>>> adj_list;
    std::vector<int> parent;
};

