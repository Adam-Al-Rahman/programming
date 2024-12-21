// Search in Sorted Matrix

// You're given a two-dimensional array (a matrix) of distinct integers and a target integer. Each row
// in the matrix is sorted, and each column is also sorted; the matrix doesn't necessarily have the
// same height and width.

// Write a function that returns an array of the row and column indices of the target integer if it's
// contained in the matrix, otherwise [-1, -1]

#include <cassert>
#include <vector>

std::vector<int> searchInSortedMatrix(const std::vector<std::vector<int>>& matrix, int target) {
  int row = 0;
  int col = matrix[0].size() - 1;

  while (row < matrix.size() && col >= 0) {
    if (matrix[row][col] > target)
      col -= 1;
    else if (matrix[row][col] < target)
      row += 1;
    else
      return {row, col};
  }

  return {-1, -1};
}

int main() {
  std::vector<std::vector<int>> matrix{
      {1, 4, 7, 12, 15, 1000},    {2, 5, 19, 31, 32, 1001},       {3, 8, 24, 33, 35, 1002},
      {40, 41, 42, 44, 45, 1003}, {99, 100, 103, 106, 128, 1004},
  };
  std::vector<int> expected{3, 3};
  assert(searchInSortedMatrix(matrix, 44) == expected);
}
