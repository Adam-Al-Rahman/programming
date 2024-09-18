// Copyright 2024 Adam-Al-Rahman

/**
You're given a list of edges representing a connected, unweighted, undirected graph with at
least one node. Write a function that returns a boolean representing whether the given graph is
two-colorable.

A graph is two-colorable (also called bipartite) if all of the nodes can be assigned one of two
colors such that no nodes of the same color are connected by an edge.

The given list is what's called an adjacency list, and it represents a graph. The number of vertices
in the graph is equal to the length of edges , where each index i in edges contains vertex
i 's siblings, in no particular order. Each individual edge is represented by a positive integer that
denotes an index in the list that this vertex is connected to. Note that this graph is undirected,
meaning that if a vertex appears in the edge list of another vertex, then the inverse will also be
true.

Also note that this graph may contain self-loops. A self-loop is an edge that has the same
destination and origin; in other words, it's an edge that connects a vertex to itself. Any self-loop
should make a graph not 2-colorable.

A graph is bipartite if and only if it has no odd-length cycles.
*/

#include <cassert>
#include <cstdint>
#include <queue>
#include <vector>

/**
-1: No color
0: First Color
1: Second Color
*/

bool check_bipartite(int start, const std::vector<std::vector<int>>& graph, std::vector<std::int8_t>& color) {
  color[start] = 0;  // Start coloring with 0

  std::queue<int> nodes;
  nodes.push(start);

  while (!nodes.empty()) {
    int current = nodes.front();
    nodes.pop();

    for (int neighbor : graph[current]) {
      if (color[neighbor] == -1) {
        // Assign alternate color to the neighbor
        color[neighbor] = 1 - color[current];
        nodes.push(neighbor);
      } else if (color[neighbor] == color[current]) {
        // If neighbor has the same color, the graph is not bipartite
        return false;
      }
    }
  }

  return true;
}

bool twoColorable(const std::vector<std::vector<int>>& graph) {
  std::vector<std::int8_t> color(graph.size(), -1);  // -1 indicates no color, 0 and 1 are the two colors.

  for (int start = 0; start < graph.size(); ++start) {
    if (color[start] == -1) {  // Only start BFS if this node hasn't been colored yet
      if (!check_bipartite(start, graph, color)) return false;
    }
  }

  return true;
}

int main() {
  std::vector<std::vector<int>> input = {{1, 2}, {0, 2}, {0, 1}};
  auto expected = false;
  auto actual = twoColorable(input);
  assert(expected == actual);
}
