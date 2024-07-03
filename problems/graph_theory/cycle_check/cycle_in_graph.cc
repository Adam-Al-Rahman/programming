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

bool cycleInGraph(std::vector<std::vector<int>> edges) {}

int main() {
  std::vector<std::vector<int>> input = {{1, 3}, {2, 3, 4}, {0}, {}, {2, 5}, {}};
  auto expected = true;
  auto actual = cycleInGraph(input);
  std::cout << (expected == actual);
}



