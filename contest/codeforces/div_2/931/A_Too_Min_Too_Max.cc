/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question:
 * @brief:
 * @source:
 * @tags: ["topics/", "algorithms/", "methods/"]
 * @status: solved
 */

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

std::int64_t too_min_too_max(std::vector<std::int64_t> &an) {
  //
  //
  std::sort(an.begin(), an.end());

  std::int64_t ai = an[0];
  std::int64_t aj = an[an.size() - 2];
  std::int64_t ak = an[1];
  std::int64_t al = an[an.size() - 1];

  return std::abs(ai - aj) + std::abs(aj - ak) + std::abs(ak - al) +
         std::abs(al - ai);
}

int main() {
  std::uint16_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint16_t n;
    std::cin >> n;

    std::vector<std::int64_t> ai(n);
    for (std::int64_t &element : ai) {
      std::cin >> element;
    }

    std::cout << too_min_too_max(ai) << '\n' << std::flush;
  }
}
