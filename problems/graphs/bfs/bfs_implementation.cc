/**
 * @filename bfs_implementation.cc
 * @brief Implementation of breadth first search algorithm for graph.
 * @copyright
 * Copyright 2024 Adam-Al-Rahman.
 */

#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

// Data structure to store a graph edge
struct Edge {
  std::int16_t src;
  std::int16_t dest;
};

class Graph {
 public:
  std::optional<std::string> graph_data;
  std::vector<std::vector<std::int16_t>> children;

  Graph(std::vector<Edge> &edges) {
    // Initialize children vector with the maximum possible size
    // This should be based on the maximum vertex index in your graph
    children.resize(edges.size() + 1);

    // add edges to the undirected graph
    for (Edge &edge : edges) {
      children[edge.src].push_back(edge.dest);
      children[edge.dest].push_back(edge.src);
    }
  }

  void breadth_first_search(std::queue<std::int16_t> &to_process,
                            std::vector<bool> &discovered) {
    if (to_process.empty()) return;

    // dequeue front node and print it
    std::int16_t v = to_process.front();
    std::cout << "Node value: " << v << std::endl;
    to_process.pop();  // pop remove front element

    // recursively process each unvisited neighbour
    for (std::int16_t u : children[v]) {
      if (!discovered[u]) {
        // mark it as discovered and enqueue it
        discovered[u] = true;
        to_process.push(u);
      }
    }

    // recursively call the function for the next level
    breadth_first_search(to_process, discovered);
  }
};

int main() {
  std::vector<Edge> edges = {
      {1, 2},  {1, 3}, {1, 4}, {2, 5},  {2, 6}, {5, 9},
      {5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
      // vertex 0, 13, and 14 are single nodes
  };

  Graph graph(edges);

  std::vector<bool> discovered(false);

  std::queue<std::int16_t> to_process;

  // perform BFS for undiscovered nodes
  for (int i = 0; i < edges.size() + 1; i++) {
  };
}
