/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Parallel Search
 * @brief:
 * @source:
 * @tags: ["topics/array", "algorithms/", "methods/parallel_execution"]
 * @status: solved
 */

#include <algorithm>
#include <execution>  // std::excution::par
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int target = 5;

  // std::execution::par only use when array is very large
  auto result = std::find(std::execution::par, vec.begin(), vec.end(), target);
  if (result != vec.end()) {
    std::cout << "Found target " << target << " at index "
              << std::distance(vec.begin(), result) << std::endl;
  } else {
    std::cout << "Target " << target << " not found." << std::endl;
  }
}
