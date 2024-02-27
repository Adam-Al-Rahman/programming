/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Maze
 * @brief:
 * @source:
 * @tags: ["topics/recursion", "algorithms/", "methods/backtracking"]
 * @status: solved
 */

#include <cstdint>

std::int16_t count_maze_paths(std::int16_t row, std::int16_t col) {
  if (row == 1 || col == 1) return 1;
  std::int16_t left = count_maze_paths(row - 1, col);
  std::int16_t right = count_maze_paths(row, col - 1);

  return left + right;
}

int main() {}
