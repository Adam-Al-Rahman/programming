/**
 * @filename bfs_implementation.cc
 * @brief Implementation of breadth first search algorithm for graph.
 * @copyright
 * Copyright 2024 Adam-Al-Rahman.
 */

#include <iostream>
#include <memory>
#include <optional>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

// Data structure to store a graph edge
struct Edge {
  std::int16_t src;
  std::int16_t dest;
};

class Graph {
 public:
  std::optional<std::string> graph_data;
  std::unordered_map<std::int16_t, std::vector<std::int16_t>> adjacency_list;

  explicit Graph(const std::vector<Edge> &edges) {
    // add edges to the undirected graph
    for (const Edge &edge : edges) {
      adjacency_list[edge.src].push_back(edge.dest);
      adjacency_list[edge.dest].push_back(edge.src);
    }
  }

  void add_edge(Edge edge) {
    adjacency_list[edge.src].push_back(edge.dest);
    adjacency_list[edge.dest].push_back(edge.src);
  }

  void breadth_first_search(
      std::shared_ptr<std::queue<std::int16_t>> to_process,
      std::shared_ptr<std::vector<bool>> discovered) {
    if (to_process->empty()) return;

    // dequeue front node and print it
    std::int16_t v = to_process->front();
    std::cout << "Node value: " << v << std::endl;
    to_process->pop();  // pop remove front element

    // recursively process each unvisited neighbour
    for (std::int16_t u : adjacency_list[v]) {
      if (!discovered->at(u)) {
        // mark it as discovered and enqueue it
        discovered->at(u) = true;
        to_process->push(u);
      }
    }

    // recursively call the function for the next level
    breadth_first_search(to_process, discovered);
  }
};

int main() {
  // Example edges
  std::vector<Edge> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4},
                             {2, 5}, {2, 6}, {3, 7}, {4, 8}};

  // Create a graph
  Graph graph(edges);

  // Add another edge
  graph.add_edge({5, 9});

  // Print graph using adjacency list
  std::cout << "Graph using adjacency list:\n";
  for (const auto &pair : graph.adjacency_list) {
    std::cout << pair.first << " -> ";
    for (std::int16_t neighbor : pair.second) {
      std::cout << neighbor << " ";
    }
    std::cout << "\n";
  }

  // Perform Breadth-First Search starting from node 0
  std::cout << "\nBreadth-First Search starting from node 0:\n";
  std::shared_ptr<std::queue<std::int16_t>> to_process =
      std::make_shared<std::queue<std::int16_t>>();
  std::shared_ptr<std::vector<bool>> discovered =
      std::make_shared<std::vector<bool>>(10, false);

  to_process->push(0);       // start from node 0
  discovered->at(0) = true;  // mark it as discovered

  graph.breadth_first_search(to_process, discovered);
}
