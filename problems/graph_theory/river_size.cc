// Copyright 2024 Adam-Al-Rahman
// River Size

// You're given a two-dimensional array (a matrix) of potentially unequal height and width
// containing only 0's sand 1's. Each 0 represents land, and each 1 represents part ofa river. A
// river consists of any number of 1 s that are either horizontally or vertically adjacent (but not
// diagonally adjacent). The number of adjacent 1 s forming a river determine its size.

// Note that a river can twist. In other words, it doesn't have to be a straight vertical line or a
// straight horizontal line; it can be L-shaped, for example.

// Write a function that returns an array of the sizes of all rivers represented in the input matrix.
// The sizes don't need to be in any particular order.

#include <algorithm>
#include <cassert>
#include <vector>

std::vector<std::vector<int>> getUnvisitedNeighbors(int i, int j, std::vector<std::vector<int>>& matrix,
                                                    std::vector<std::vector<int>>& visited) {
  std::vector<std::vector<int>> unvisitedNeighbors{};

  if (i > 0 && !visited[i - 1][j]) unvisitedNeighbors.push_back({i - 1, j});
  if (i < matrix.size() - 1 && !visited[i + 1][j]) unvisitedNeighbors.push_back({i + 1, j});
  if (j > 0 && !visited[i][j - 1]) unvisitedNeighbors.push_back({i, j - 1});
  if (j < matrix[0].size() - 1 && !visited[i][j + 1]) unvisitedNeighbors.push_back({i, j + 1});

  return unvisitedNeighbors;
}

void traverseNode(int i, int j, std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& visited,
                  std::vector<int>& sizes) {
  int currentRiverSize = 0;
  std::vector<std::vector<int>> nodesToExplore{{i, j}};

  while (!nodesToExplore.empty()) {
    std::vector<int> currentNode = nodesToExplore.back();
    nodesToExplore.pop_back();
    i = currentNode[0];
    j = currentNode[1];

    if (visited[i][j]) continue;
    visited[i][j] = true;

    if (matrix[i][j] == 0) continue;

    currentRiverSize += 1;
    std::vector<std::vector<int>> unvisitedNeighbors = getUnvisitedNeighbors(i, j, matrix, visited);

    for (std::vector<int> neighbor : unvisitedNeighbors) nodesToExplore.push_back(neighbor);
  }

  if (currentRiverSize > 0) sizes.push_back(currentRiverSize);
}

// TC: O(wh) | SC: O(wh)
std::vector<int> riverSizes(std::vector<std::vector<int>> matrix) {
  std::vector<int> sizes = {};
  std::vector<std::vector<int>> visited(matrix.size(), std::vector<int>(matrix[0].size(), false));

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      if (visited[i][j]) continue;
      traverseNode(i, j, matrix, visited, sizes);
    }
  }

  return sizes;
}

int main() {
  std::vector<std::vector<int>> testInput{
      {1, 0, 0, 1, 0}, {1, 0, 1, 0, 0}, {0, 0, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 0},
  };
  std::vector<int> expected{1, 2, 2, 2, 5};
  std::vector<int> output = riverSizes(testInput);
  std::sort(output.begin(), output.end());
  assert(output == expected);
}
