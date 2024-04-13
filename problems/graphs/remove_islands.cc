/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Remove Islands
 * @brief:
 * @source:
 * @tags: ["topics/graph", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <iostream>
#include <vector>

std::vector<std::vector<int>> remove_islands(
    std::vector<std::vector<int>> matrix) {}

int main() {
  std::vector<std::vector<int>> input = {
      {1, 0, 0, 0, 0, 0}, {0, 1, 0, 1, 1, 1}, {0, 0, 1, 0, 1, 0},
      {1, 1, 0, 0, 1, 0}, {1, 0, 1, 1, 0, 0}, {1, 0, 0, 0, 0, 1},
  };
  std::vector<std::vector<int>> expected = {
      {1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 1}, {0, 0, 0, 0, 1, 0},
      {1, 1, 0, 0, 1, 0}, {1, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 1},
  };
  auto actual = remove_islands(input);

  std::cout << "Result" << (expected == actual);
}
