/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Powerset
 * @brief: return a list of all powerset
 * @source:
 * @tags: ["topics/recursion", "algorithms/", "methods/backtracking"]
 * @status: solved
 */

#include <cstdint>
#include <iostream>
#include <vector>

std::vector<std::vector<int32_t>> powerset(
    std::vector<std::int32_t> numbers, std::vector<std::int32_t> result = {}) {
  if (numbers.empty()) return {result};

  std::int32_t element = numbers[0];

  result.push_back(element);
  numbers.erase(numbers.begin());
  std::vector<std::vector<std::int32_t>> left = powerset(numbers, result);

  result.pop_back();
  std::vector<std::vector<std::int32_t>> right = powerset(numbers, result);

  left.insert(left.end(), right.begin(), right.end());
  return left;
}

int main() {
  std::vector<std::int32_t> array = {1, 2, 3};

  std::cout << "{ ";
  auto it = powerset(array);
  for (std::vector<std::int32_t> sub_powerset : it) {
    std::cout << ", { ";
    for (std::int32_t element : sub_powerset) {
      std::cout << element << ',';
    }
    std::cout << " }";
  }
  std::cout << " }";
}
