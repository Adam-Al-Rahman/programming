/**
 * Copyright 2024 Adam-Al-Rahman
 */

/**
 * std::greater:
 *
 * https://en.cppreference.com/w/cpp/utility/pair/operator_cmp#:~:text=3%2D6)-,Compares,elements%20and%20only%20if%20they%20are%20equivalent%2C%20compares%20the%20second%20elements.,-7)

 */

#include <algorithm>
#include <iostream>
#include <limits>   // std::numeric_limits
#include <queue>    // std::priority_queue
#include <utility>  // std::pair
#include <vector>

struct Edge {
  int weight;
  int dest;

  Edge(int d, int w) : dest(d), weight(w) {}

  // Convertion operator to std::pair
  operator std::pair<int, int>() { return std::make_pair(weight, dest); }
};

void dijkstra(int src, std::vector<std::vector<Edge>>& graph, std::vector<int>& weights, std::vector<int>& parent) {
  weights[src] = 0;

  // Min-Heap based weights;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> nodes;
  nodes.push({0, src});  // Node: Required Format {weight, node} for std::greater

  std::vector<bool> visited(graph.size(), false);

  while (!nodes.empty()) {
    auto [current_weight, current] = nodes.top();
    nodes.pop();

    if (visited[current]) continue;
    visited[current] = true;

    for (auto& [neighbor_weight, neighbor] : graph[current]) {
      int new_weight = current_weight + neighbor_weight;

      if (new_weight < weights[neighbor]) {
        weights[neighbor] = new_weight;
        parent[neighbor] = current;
        nodes.push({new_weight, neighbor});
      }
    }
  }
}

int main() {
  int vertices;
  std::cin >> vertices;

  int edges;
  std::cin >> edges;

  std::vector<std::vector<Edge>> graph(vertices);

  // Adding edges to the graph
  for (int i = 0; i < edges; ++i) {
    int src, dest, weight;
    std::cin >> src >> dest >> weight;
    graph[src].push_back(Edge(dest, weight));
  }

  int source = 0;
  std::vector<int> weights(vertices, std::numeric_limits<int>::max());
  std::vector<int> parent(vertices, -1);  // Keep track of the src->dest path

  dijkstra(source, graph, weights, parent);  // In-place operation

  // Outputting the shortest paths from the source
  std::cout << "Shortest paths from node " << source << ":\n";
  for (int i = 0; i < vertices; ++i) {
    std::cout << "To node " << i << ": ";
    if (weights[i] == std::numeric_limits<int>::max()) {
      std::cout << "No path\n";
    } else {
      std::cout << weights[i] << " (via ";
      std::vector<int> path;
      for (int v = i; v != -1; v = parent[v]) {
        path.push_back(v);
      }
      std::reverse(path.begin(), path.end());
      for (int v : path) {
        std::cout << v << " ";
      }
      std::cout << ")\n";
    }
  }

  return 0;
}
