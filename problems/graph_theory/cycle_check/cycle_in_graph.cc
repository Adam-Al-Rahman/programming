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
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

struct PairHash {
  std::size_t operator()(const std::pair<int, int>& pair) const {
    // Combine the hash values of the pair's elements
    return std::hash<int>()(pair.first) ^ std::hash<int>()(pair.second);
  }
};

bool cycleInGraph(std::vector<std::vector<int>> edges) {
  if (edges.empty()) return false;

  std::unordered_map<std::pair<int, int>, bool, PairHash> exists;

  std::stack<std::pair<int, int>> nodes;
  nodes.push(std::make_pair(0, edges[0][0]));

  while (!nodes.empty()) {
    std::pair<int, int> current = nodes.top();
    nodes.pop();

    if (exists[current]) return true;
    exists[current] = true;

    if (edges[current.first].empty() && (current.first + 1 < edges.size()))
      nodes.push(std::make_pair(current.first + 1, current.second));
    for (auto it = edges[current.first].rbegin(); it != edges[current.first].rend(); it++)
      nodes.push(std::make_pair(current.first, *it));
  }

  return false;
}

int main() {
  std::vector<std::vector<int>> input = {{1, 3}, {2, 3, 4}, {0}, {}, {2, 5}, {}};
  auto expected = true;
  auto actual = cycleInGraph(input);
  std::cout << (expected == actual);
}
