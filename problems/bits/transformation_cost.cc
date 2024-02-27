/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Transformation Cost
 * @brief:
 * @source: https://www.codechef.com/problems/TRANCST?tab=statement
 * @tags: ["topics/bit_manipulation", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <bitset>
#include <iostream>

bool bits_subsequence(const std::bitset<8>& sequence,
                      const std::bitset<8>& subsequence) {
  for (size_t i = 0; i <= sequence.size() - subsequence.size(); i++) {
    if ((sequence >> i & subsequence) == subsequence) {
      return true;
    }
  }
  return false;
}

std::uint64_t transformation_cost(std::uint64_t n) { return 0; }

int main() {
  std::uint32_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint64_t n;
    std::cin >> n;

    std::cout << transformation_cost(n) << '\n' << std::flush;
  }
}
