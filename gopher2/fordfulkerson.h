#pragma once

#include <vector>
#include <set>

struct FlowEdge {
	int from;
	int to;
	int capacity;

    int getCost() const {
        return 0;
    }
};

struct CostFlowEdge {
	int from;
	int to;
	int capacity;
    int cost;

    int getCost() const {
        return cost;
    }
};

struct FlowResult {
	int flow;
    std::vector<FlowEdge> edges;
};

struct MinCostMaxFlowResult {
    int flow;
    int cost;
    std::vector<CostFlowEdge> edges;
};

struct MinCutEdgesResult {
	int cost;
    std::vector<FlowEdge> edges;
};

/*
 * Solve a flow problem using the Edmonds-Karp version of the Ford-Fulkerson algorithm. 
 * 
 * Runs in time O(|N|*|V|^2)
 */
FlowResult maxFlow(const std::vector<FlowEdge> &edges, int nr_of_nodes, int source, int sink);


/**
 * Finds the maximum flow between the source and the sink, using the cheapest possible edges to achieve this.
 *
 * Note that the total cost of the edges may not exceed 1000000, if they do, the solution is not guarenteed
 * to be correct.
 */
MinCostMaxFlowResult minCostMaxFlow(const std::vector<CostFlowEdge> &edges, int nr_of_nodes, int source, int sink);


/*
 * Find a minimal subset of edges that separates the source from the sink. The subset will be minimal
 * in respect to the sum of the weights of the edges. 
 * 
 * Runs in time O(|N|*|V|^2)
 */
MinCutEdgesResult minCutEdges(const std::vector<FlowEdge> &edges, int nr_of_nodes, int source, int sink);

/*
 * Find a subset of nodes that separates the source from the sink such that the sum of the edges
 * from the subset to the nodes not in the set is minimal. 
 * 
 * Runs in time O(|N|*|V|^2)
 */
std::set<int> minCutNodes(const std::vector<FlowEdge> &edges, int nr_of_nodes, int source, int sink);



