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
#include <queue>
#include <utility>
#include <vector>

void non_islands(std::vector<std::vector<int>> &matrix,          // NOLINT (non-const)
                 std::vector<std::vector<bool>> &is_non_island,  // NOLINT (non-const)
                 int x = 0, int y = 0) {
  //
  std::queue<std::pair<int, int>> nodes;
  nodes.push(std::make_pair(x, y));

  int rows = matrix.size();
  int cols = matrix[0].size();

  while (!nodes.empty()) {
    std::pair<int, int> current = nodes.front();
    nodes.pop();

    if (current.first < 0 || current.first >= rows || current.second < 0 || current.second >= cols ||
        matrix[current.first][current.second] == 0)
      continue;

    if (matrix[current.first][current.second] == 1 && !is_non_island[current.first][current.second])
      is_non_island[current.first][current.second] = true;
    else if (matrix[current.first][current.second] == 1 &&
             is_non_island[current.first][current.second])  // if adjacent node are set true
                                                            // then skip it.
      continue;

    nodes.push(std::make_pair(current.first + 1, current.second));
    nodes.push(std::make_pair(current.first - 1, current.second));
    nodes.push(std::make_pair(current.first, current.second + 1));
    nodes.push(std::make_pair(current.first, current.second - 1));
  }
}

std::vector<std::vector<int>> remove_islands(std::vector<std::vector<int>> &matrix) {  // NOLINT (non-const)
  int rows = matrix.size();
  int columns = matrix[0].size();
  std::vector<std::vector<bool>> is_non_island(matrix.size(), std::vector<bool>(matrix[0].size(), false));

  for (int i = 0; i < rows; i++) non_islands(matrix, is_non_island, i, 0);
  for (int i = 0; i < rows; i++) non_islands(matrix, is_non_island, i, columns - 1);

  for (int i = 0; i < columns; i++) non_islands(matrix, is_non_island, 0, i);
  for (int i = 0; i < columns; i++) non_islands(matrix, is_non_island, rows - 1, i);

  for (int i = 1; i < rows - 1; i++) {
    for (int j = 1; j < columns - 1; j++) {
      if (is_non_island[i][j] == false) matrix[i][j] = 0;
    }
  }
  return matrix;
}

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
