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
#include <vector>

std::vector<std::uint16_t> river_size(
    std::vector<std::vector<std::uint16_t>> &matrix,  // NOLINT (non-const)
    std::uint16_t x = 0, std::uint16_t y = 0, std::uint16_t count = 0) {
  //
  if (matrix[x][y] == 0) {
    return {count};
  } else {
    count++;
    matrix[x][y] = 0;
  }

  std::size_t n = matrix.size();
  std::size_t m = matrix[0].size();

  std::vector<std::uint16_t> sizes;
  if ((x + 1) >= 0 && (x + 1) < n && matrix[x + 1][y] != 0) {
    std::vector<std::uint16_t> current_size = river_size(matrix, x + 1, y);
    sizes.insert(sizes.end(), current_size.begin(), current_size.end());
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
