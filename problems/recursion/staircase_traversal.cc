/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question:Staircase Traversal
 * @brief:
 * @source:
 * @tags: ["topics/recursion", "algorithms/", "methods/backtracking"]
 * @status: unsolved
 */

#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

// Alternative Approach: Sliding Windows
/**
int staircaseTraversal(int height, int maxSteps) {
  int current_num_ways = 0;
  std::vector<int> ways_top;
  ways_top.push_back(1);

  for(int i = 1; i <= height; i++){
    int start_window = i - maxSteps - 1;
    int end_window = i - 1;

    if (start_window >= 0) current_num_ways -= ways_top[start_window];

    current_num_ways += ways_top[end_window];
    ways_top.push_back(current_num_ways);
  }

  return ways_top[height];
}
*/
std::int32_t staircase_traversal_rec(std::int32_t height,
                                     std::vector<std::int32_t> steps,
                                     std::vector<std::int32_t> result = {}) {
  std::int32_t ways = 0;
  std::int32_t result_sum = std::accumulate(result.begin(), result.end(), 0);
  if (result_sum == height) {
    ways = 1;
    return ways;
  }

  if (result_sum > height) {
    return ways;
  }

  for (int i = 0; i < steps.size(); i++) {
    result.push_back(steps[i]);
    ways += staircase_traversal_rec(height, steps, result);
    result.pop_back();
  }

  return ways;
}

std::int32_t staircase_traversal(std::int32_t height, std::int32_t max_steps) {
  std::vector<std::int32_t> steps;

  for (int i = 1; i <= max_steps; i++) {
    steps.push_back(i);
  }

  return staircase_traversal_rec(height, steps);
}

int main() {
  std::int32_t height = 4;
  std::int32_t max_steps = 2;

  std::cout << staircase_traversal(height, max_steps) << '\n';
}
