/*
 * @question: Minimum & Maximum elements
 * @brief: Find the minimum and maximum element from the list
 * @source:
 * https://www.geeksforgeeks.org/recursive-programs-to-find-minimum-and-maximum-elements-of-array/
 * @tags: ["recursion", "array", "search"]
 * @status: unsolved
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, int> min_max_element(
    const std::vector<int> &list, int max = 0, int min = 0, int n = 0) {
  if (list[n] > max) max = list[n];
  if (list[n] < min) min = list[n];

  if (n > list.size()) return {{"min", min}, {"max", max}};

  return min_max_element(list, max, min, n + 1);
}

int main() {
  std::unordered_map<std::string, int> elements =
      min_max_element({1, 4, 3, -5, -4, 8, 6});

  std::cout << "Min: " << elements["min"] << "\n";
  std::cout << "Max: " << elements["max"] << std::flush;
}
