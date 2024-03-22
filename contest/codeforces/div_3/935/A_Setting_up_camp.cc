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

// each tent: max 3 people
// introvert: live alone
// extroverts: extrovert + two others
// universal: alone, 1, 2

#include <cmath>
#include <cstdint>
#include <iostream>

int main() {
  std::uint16_t tests;
  std::cin >> tests;

  while (tests--) {
    // introverts, extroverts, universals
    std::uint64_t a, b, c;
    std::cin >> a >> b >> c;

    std::int64_t num_tents = a;

    if (b % 3 == 0) {
      num_tents += (b / 3);
      num_tents += std::ceil(static_cast<double>(c) / 3);
    } else if (b % 3 == 1 && c >= 2) {
      num_tents += (b / 3);
      num_tents += 1;
      if ((c - 2) < 3 && (c - 2) != 0) {
        num_tents += 1;
      } else {
        num_tents += std::ceil(static_cast<double>(c - 2) / 3);
      }
    } else if (b % 3 == 2 && c >= 1) {
      num_tents += (b / 3);
      num_tents += 1;
      if ((c - 1) < 3 && (c - 1) != 0) {
        num_tents += 1;
      } else {
        num_tents += std::ceil(static_cast<double>(c - 1) / 3);
      }
    } else {
      num_tents = -1;
    }
    std::cout << num_tents << std::endl;
  }
}
