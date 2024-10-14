// Spiral Traverse

// Write a function that takes in an n x m two-dimensional array (that can be square-
// shaped when n == m) and returns a one-dimensional array of all the array's elements in
// spiral order.
// Spiral order starts at the top left corner of the two-dimensional array, goes to the right,
// and proceeds in a spiral pattern all the way until every element has been visited.

#include <cassert>
#include <vector>

std::vector<int> spiralTraverse(std::vector<std::vector<int>> array) {
  if (array.empty()) return {};  // Early return if the input is empty

  std::vector<int> result;

  int row_start = 0;
  int row_end = array.size() - 1;

  int col_start = 0;
  int col_end = array[0].size() - 1;

  while (row_start <= row_end && col_start <= col_end) {
    // Traverse the top row
    for (int col = col_start; col <= col_end; ++col) result.push_back(array[row_start][col]);
    row_start += 1;

    // Traverse the right column
    for (int row = row_start; row <= row_end; ++row) result.push_back(array[row][col_end]);
    col_end -= 1;

    // Traverse the bottom row (only if it still exists)
    if (row_start <= row_end) {
      for (int col = col_end; col >= col_start; --col) result.push_back(array[row_end][col]);
      row_end -= 1;
    }

    // Traverse the left column (only if it still exists)
    if (col_start <= col_end) {
      for (int row = row_end; row >= row_start; --row) result.push_back(array[row][col_start]);
      col_start += 1;
    }
  }

  return result;
}

int main() {
  std::vector<std::vector<int>> input = {
      {1, 2, 3, 4},
      {12, 13, 14, 5},
      {11, 16, 15, 6},
      {10, 9, 8, 7},
  };

  std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  std::vector<int> actual = spiralTraverse(input);
  assert(expected == actual);
}
