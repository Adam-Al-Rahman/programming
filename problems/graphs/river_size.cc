/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: River Size
 * @brief: Given a matrix of 1 and 0, where 1 indicates rivers, now count the
 * consicative 1 as it size.
 * @source:
 * @tags: ["topics/graph", "algorithms/", "methods/recursion"]
 * @status: unsolved
 */

#include <cstdint>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> get_unvisited_neighbors(
    std::vector<std::vector<std::uint16_t>> &matrix,  // NOLINT (non-const)
    std::vector<std::vector<bool>> &visited, int i,   // NOLINT (non-const)
    int j) {
  std::vector<std::pair<int, int>> unvisited_neighbors;

  if (i > 0 && !visited[i - 1][j])
    unvisited_neighbors.push_back(std::make_pair(i - 1, j));
  if ((i < matrix.size() - 1) && !visited[i + 1][j])
    unvisited_neighbors.push_back(std::make_pair(i + 1, j));
  if ((j < matrix[0].size() - 1) && !visited[i][j + 1])
    unvisited_neighbors.push_back(std::make_pair(i, j + 1));
  if (j > 0 && !visited[i][j - 1])
    unvisited_neighbors.push_back(std::make_pair(i, j - 1));

  return unvisited_neighbors;
}

void traverse_node(
    std::vector<std::vector<std::uint16_t>> &matrix,  // NOLINT (non-const)
    std::vector<std::vector<bool>> &visited,          // NOLINT (non-const)
    std::vector<std::uint16_t> sizes, int i, int j) {
  int current_river_size = 0;

  std::stack<std::pair<int, int>> to_explore;
  to_explore.push(std::make_pair(i, j));

  while (!to_explore.empty()) {
    std::pair<int, int> current_nodes = to_explore.top();
    to_explore.pop();

    i = current_nodes.first;
    j = current_nodes.second;

    if (visited[i][j]) continue;
    visited[i][j] = true;

    if (matrix[i][j] == 0) continue;

    current_river_size += 1;
    std::vector<std::pair<int, int>> unvisited_neighbors =
        get_unvisited_neighbors(matrix, visited, i, j);

    for (auto &neighbor : unvisited_neighbors) {
      to_explore.push(neighbor);
    }
  }

  if (current_river_size > 0) sizes.push_back(current_river_size);
}

std::vector<std::uint16_t> river_size(
    std::vector<std::vector<std::uint16_t>> &matrix) {  // NOLINT (non-const)
  //
  std::vector<uint16_t> sizes;
  std::vector<std::vector<bool>> visited(
      matrix.size(), std::vector<bool>(matrix[0].size(), false));

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      if (visited[i][j]) continue;
      traverse_node(matrix, visited, sizes, i, j);
    }
  }

  return sizes;
}

int main() {
  std::vector<std::vector<std::uint16_t>> matrix = {
      {1, 0, 0, 1, 0}, {1, 0, 1, 0, 0}, {0, 0, 1, 0, 1},
      {1, 0, 1, 0, 1}, {1, 0, 1, 1, 0},
  };

  for (std::uint16_t &element : river_size(matrix)) {
    std::cout << element << ' ';
  }
  std::cout << std::flush;
}
