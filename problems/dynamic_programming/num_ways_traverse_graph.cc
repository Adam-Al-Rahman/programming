// Number Of Ways To Traverse Graph

// You're given two positive integers representing the width and height of a grid-shaped,
// rectangular graph. Write a function that returns the number of ways to reach the bottom right
// corner of the graph when starting at the top left corner. Each move you take must either go
// down or right. In other words, you can never move up or left in the graph.

#include <cassert>
#include <cmath>  // For M_PI, std::sqrt, std::pow, std::exp, std::log
#include <vector>

int numberOfWaysToTraverseGraph(int width, int height) {
  std::vector<std::vector<int>> cache(height, std::vector<int>(width, 0));
  cache[0][0] = 1;  // base case

  for (int x = 0; x < height; ++x) {
    for (int y = 0; y < width; ++y) {
      if (x > 0) cache[x][y] += cache[x - 1][y];  // move from above -> [x][y]
      if (y > 0) cache[x][y] += cache[x][y - 1];  // move from left -> [x][y]
    }
  }

  return cache[height - 1][width - 1];
}

// Check out: Stirling Factorial Approximation
int factorial(int num) {
  int result = 1;

  for (int n = 2; n <= num; ++n) result *= n;

  return result;
}

int number_of_ways_to_traverse_graph_combination(int width, int height) {
  int nums_right_moves = width - 1;
  int nums_down_moves = height - 1;

  int total_moves = nums_right_moves + nums_down_moves;

  // using combination formula
  int combinations = factorial(total_moves) / (factorial(nums_right_moves) * factorial(nums_down_moves));

  return combinations;
}

int main() {
  auto width = 4;
  auto height = 3;
  auto expected = 10;
  auto actual = numberOfWaysToTraverseGraph(width, height);
  assert(expected == actual);
}
