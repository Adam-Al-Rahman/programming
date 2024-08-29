// Copyright 2024 Adam-Al-Rahman

/**
Write a function that takes in an integer matrix of potentially unequal height and width and
returns the minimum
 * number of passes required to convert all negative integers in the matrix to
positive integers.

A negative integer in
 * the matrix can only be converted to a positive integer if one or more of its
adjacent elements is positive. An
 * adjacent element is an element that is to the left, to the right,
above, or below the current element in the matrix.
 * Converting a negative to a positive simply
involves multiplying it by -1

A single pass through the matrix involves
 * converting all the negative integers that can be
converted at a particular point in time.

Note that the 0 value is
 * neither positive nor negative, meaning that 0 can't convert an
adjacent negative to a positive.

Note that the input
 * matrix will always contain at least one element. If the negative integers in the
input matrix can't all be converted
 * to positives, regardless of how many passes are run, your
function should return -1
*/

#include <cassert>
#include <queue>
#include <tuple>
#include <vector>

namespace px {
using node = std::tuple<int, int>;
}

int minimumPassesOfMatrix(std::vector<std::vector<int>> matrix) {
  int passes = 0;
  std::queue<px::node> nodes;

  // Initial population of queue with positive elements
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[i].size(); ++j) {
      if (matrix[i][j] > 0) nodes.push({i, j});
    }
  }

  // Directions for moving in the matrix: up, down, left, right
  std::vector<px::node> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  while (!nodes.empty()) {
    int current_size = nodes.size();  // Track nodes at the current "pass" level

    for (int k = 0; k < current_size; ++k) {
      auto [x, y] = nodes.front();
      nodes.pop();

      for (auto [dx, dy] : directions) {
        int nx = x + dx, ny = y + dy;

        // Check boundaries and if the neighbor is a negative number
        if (nx >= 0 && nx < matrix.size() && ny >= 0 && ny < matrix[nx].size() && matrix[nx][ny] < 0) {
          matrix[nx][ny] *= -1;  // Convert to positive
          nodes.push({nx, ny});
        }
      }
    }

    if (!nodes.empty()) {
      passes += 1;  // Only increment passes if there are more nodes to process
    }
  }

  // Check if there's any negative number left in the matrix
  for (const auto& row : matrix) {
    for (int val : row)
      if (val < 0) return -1;  // Return -1 if there's still a negative number
  }

  return passes;
}

int main() {
  std::vector<std::vector<int>> input = {{0, -1, -3, 2, 0}, {1, -2, -5, -1, -3}, {3, 0, 0, -4, -1}};
  auto expected = 3;
  auto actual = minimumPassesOfMatrix(input);
  assert(expected == actual);
}
