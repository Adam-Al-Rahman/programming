/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Find single duplicate element
 * @brief:
 * @source:
 * https://www.geeksforgeeks.org/find-element-appears-array-every-element-appears-twice
 * @tags: ["topics/bits", "algorithms/", "methods/bit_manipulation"]
 * @status: unsolved
 */

/** XOR properties
 *
Let us consider the above example.
Let ^ be xor operator as in C and C++.

res = 7 ^ 3 ^ 5 ^ 4 ^ 5 ^ 3 ^ 4

Since XOR is associative and commutative, above
expression can be written as:
res = 7 ^ (3 ^ 3) ^ (4 ^ 4) ^ (5 ^ 5)
    = 7 ^ 0 ^ 0 ^ 0
    = 7 ^ 0
    = 7
 *
*/

#include <cstdint>
#include <iostream>
#include <vector>

// only work for single duplicate elements
std::int16_t find_duplicate(const std::vector<std::int16_t> &list) {
  std::int16_t duplicate = list[0];

  for (std::size_t i = 1; i < list.size(); i++) {
    duplicate ^= list[i];
  }

  return duplicate;
}

int main() {
  std::vector<std::int16_t> list = {2, 5, 3, 4, 3};

  std::cout << "Duplicate element: " << find_duplicate(list) << std::flush;
}
