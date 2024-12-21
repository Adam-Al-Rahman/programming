// Zig Zag Traverse

// Write a function that takes in an n x m two-dimensional array (that can be square-shaped when
// n m) and returns a one-dimensional array of all the array's elements in zigzag order.

// Zigzag order starts at the top left corner of the two-dimensional array, goes down by one
// element, and proceeds in a zigzag pattern all the way to the bottom right corner.

#include <cassert>
#include <vector>

bool isOutOfBound(int row, int col, int height, int width) { return row < 0 || row > height || col < 0 || col > width; }

std::vector<int> zigzagTraverse(std::vector<std::vector<int>> array) {
  int height = array.size() - 1;
  int width = array[0].size() - 1;

  std::vector<int> result = {};
  int row = 0;
  int col = 0;
  bool goingDown = true;

  while (!isOutOfBound(row, col, height, width)) {
    result.push_back(array[row][col]);

    if (goingDown) {
      if (col == 0 || row == height) {
        goingDown = false;
        if (row == height)
          col += 1;
        else
          row += 1;
      } else {
        row += 1;
        col -= 1;
      }
    } else {
      if (row == 0 || col == width) {
        goingDown = true;
        if (col == width)
          row += 1;
        else
          col += 1;
      } else {
        row -= 1;
        col += 1;
      }
    }
  }

  return result;
}

int main() {
  std::vector<std::vector<int>> test = {{1, 3, 4, 10}, {2, 5, 9, 11}, {6, 8, 12, 15}, {7, 13, 14, 16}};
  std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  assert(zigzagTraverse(test) == expected);
}
