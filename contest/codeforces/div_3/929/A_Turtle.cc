/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Turtle Puzzle
 * @brief:
 * @source:
 * @tags: ["topics/", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

std::int32_t turtle_puzzle(std::vector<std::int16_t> ai) {
  std::sort(ai.begin(), ai.end());

  for (std::int16_t& element : ai) {
    if (element < 0) {
      element = -1 * element;
    }
  }

  return std::accumulate(ai.begin(), ai.end(), 0);
}

int main() {
  std::uint16_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint16_t n;
    std::cin >> n;

    std::vector<std::int16_t> ai(n);
    for (std::int16_t& element : ai) {
      std::cin >> element;
    }

    std::cout << turtle_puzzle(ai) << '\n' << std::flush;
  }
}
