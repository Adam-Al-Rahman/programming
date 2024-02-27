/*
 * @question: Sum Triangle
 * @brief: From a given array form a triangle where at each step the sum is same
 * and number of elements reduced by 1
 * @source:
 * https://www.geeksforgeeks.org/sum-triangle-from-array/
 * @tags: ["recursion", "array"]
 * @status: solved
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

#include <iostream>
#include <vector>

void sum_triangle(const std::vector<int> &list) {
  std::vector<int> current_sum_list;
  for (std::size_t i = 1; i < list.size(); i++) {
    current_sum_list.push_back(list[i - 1] + list[i]);
  }

  if (current_sum_list.size() == 0) return;

  sum_triangle(current_sum_list);
  std::cout << "[ ";
  for (int element : current_sum_list) {
    std::cout << element << " ";
  }
  std::cout << "]"
            << "\n"
            << std::flush;
}

int main() { sum_triangle({1, 2, 3, 4, 5}); }
