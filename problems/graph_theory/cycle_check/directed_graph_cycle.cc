// Copyright 2024 Adam-Al-Rahman

/**
You're given a list of edges representing an unweighted, directed graph with at
least one node. Write a function
 * that returns a boolean representing whether the
given graph contains a cycle.
*/

// HEADERS (Required)
#include <cassert>
#include <stack>
#include <vector>

bool cycleInGraph(std::vector<std::vector<int>>& graph) {
  std::vector<bool> visited(graph.size(), false);
  std::vector<bool> in_stack(graph.size(), false);

  std::stack<int> nodes;

  for (int i = 0; i < graph.size(); ++i) {
    if (visited[i]) continue;
    nodes.push(i);

    while (!nodes.empty()) {
      auto current = nodes.top();

      if (!visited[current]) {
        visited[current] = true;
        in_stack[current] = true;
      } else {
        in_stack[current] = false;
        nodes.pop();
      }

      for (auto neighbor : graph[current]) {
        if (!visited[neighbor])
          nodes.push(neighbor);
        else if (in_stack[neighbor])
          return true;
      }
    }
  }

  return false;
}

int main() {
  std::vector<std::vector<int>> input = {{1, 3}, {2, 3, 4}, {0}, {}, {2, 5}, {}};
  auto expected = true;
  auto actual = cycleInGraph(input);
  assert(expected == actual);
}
