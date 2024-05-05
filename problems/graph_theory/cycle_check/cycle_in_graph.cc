/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Cycle in graph
 * @brief:
 * @source:
 * @tags: ["topics/graph", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <iostream>
#include <vector>

bool is_cycle(const std::vector<std::vector<int>>& edges, int node, std::vector<bool>& visited,  // NOLINT (non-const)
              std::vector<bool>& in_stack) {                                                     // NOLINT (non-const)
  visited[node] = true;
  in_stack[node] = true;

  std::vector<int> neighbors = edges[node];

  for (auto& neighbor : neighbors) {
    bool contains_cycle = is_cycle(edges, neighbor, visited, in_stack);
    if (!visited[neighbor]) {
      if (contains_cycle)
        return true;
      else if (in_stack[neighbor])
        return true;
    }
  }
  in_stack[node] = false;

  return false;
}

bool cycleInGraph(std::vector<std::vector<int>> edges) {
  if (edges.empty()) return false;

  std::vector<bool> visited(edges.size(), false);
  std::vector<bool> in_stack(edges.size(), false);

  for (int i = 0; i < edges.size(); i++) {
    if (visited[i]) continue;

    bool contains_cycle = is_cycle(edges, i, visited, in_stack);

    if (contains_cycle) return true;
  }

  return false;
}

int main() {
  std::vector<std::vector<int>> input = {{1, 3}, {2, 3, 4}, {0}, {}, {2, 5}, {}};
  auto expected = true;
  auto actual = cycleInGraph(input);
  std::cout << (expected == actual);
}
