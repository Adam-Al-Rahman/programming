/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: B. Array Fix
 * @brief:
 * @source:
 * @tags: ["topics/", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

std::string array_fix(const std::vector<std::uint16_t> &ai) {
  std::uint16_t prev_element = 0;
  bool is_sorted = true;

  for (const std::uint16_t &element : ai) {
    if (element >= 10 && element / 10 >= prev_element &&
        element % 10 >= (element / 10)) {
      prev_element = element % 10;
    } else {
      if (element >= prev_element) {
        prev_element = element;
      } else {
        is_sorted = false;
        break;
      }
    }
  }

  return (is_sorted ? "YES" : "NO");
}

int main() {
  std::uint16_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint16_t n;
    std::cin >> n;

    std::vector<std::uint16_t> ai(n);
    for (std::uint16_t &element : ai) {
      std::cin >> element;
    }
    std::cout << array_fix(ai) << '\n' << std::flush;
  }
}
