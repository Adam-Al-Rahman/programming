/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Turtle Puzzle
 * @brief:
 * @source:
 * @tags: ["topics/", "algorithms/", "methods/"]
 * @status: solved
 */

/**
 * in one move:
 * only one option
 * any number of move
 */

//
// sum % 3 == 0 return 0
// sum % 3 == 2 return 1
// sum % 3 == 1:
// - check each_element % 3 == 1 return 1 else return 2;

#include <iostream>
#include <numeric>
#include <vector>

std::uint32_t turtle_math(std::vector<std::uint32_t> ai) {
  std::int32_t sum = std::accumulate(ai.begin(), ai.end(), 0);

  std::int32_t sum_remainder = sum % 3;

  if (sum_remainder == 0) return 0;
  if (sum_remainder == 2) return 1;

  for (std::uint32_t& element : ai) {
    if (element % 3 == 1) return 1;
  }

  return 2;
}

int main() {
  std::uint32_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint32_t n;
    std::cin >> n;

    std::vector<std::uint32_t> ai(n);
    for (std::uint32_t& element : ai) {
      std::cin >> element;
    }

    std::cout << turtle_math(ai) << '\n' << std::flush;
  }
}
