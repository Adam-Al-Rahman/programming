/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question:
 * @brief:
 * @source:
 * @tags: ["topics/", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <iostream>
#include <vector>

std::vector<std::int32_t> permutation_print(std::uint32_t n) {
  std::vector<std::int32_t> permutations;

  std::int32_t left = 1;
  std::int32_t right = n;

  for (int i = 1; i <= n; i++) {
    if (i & 1) {  // odd case
      permutations.push_back(left);
      left++;
    } else {  // even case
      permutations.push_back(right);
      right--;
    }
  }
  return permutations;
}

int main() {
  std::int32_t test;
  std::cin >> test;

  while (test--) {
    std::uint32_t n;
    std::cin >> n;

    for (std::int32_t element : permutation_print(n)) {
      std::cout << element << ' ';
    }
  }
}
