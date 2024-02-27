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

/**
- Operation any number of times(possibley zero)
  - choose a chip and move it to the `closest free cell to the left`.

*/

#include <cstdint>
#include <iostream>
#include <vector>

std::uint16_t moving_chips(std::vector<std::uint16_t> ai) {
  std::uint16_t count = 0;
  std::uint16_t start = 0;
  std::int16_t end = ai.size() - 1;

  // Find the first occurrence of 1 from the beginning
  while (start < ai.size()) {
    if (ai[start] == 1) {
      break;
    }
    start++;
  }

  // Find the last occurrence of 1 from the end
  while (end >= 0 && start < end) {
    if (ai[end] == 1) {
      break;
    }
    end--;
  }

  if (start != end) {
    for (size_t i = start + 1; i <= end - 1; i++) {
      if (ai[i] == 0) count++;
    }
  }

  return count;
}

int main() {
  std::uint16_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint16_t n;
    std::cin >> n;

    std::vector<std::uint16_t> ai;
    for (int i = 0; i < n; i++) {
      std::uint16_t a;
      std::cin >> a;
      ai.push_back(a);
    }
    std::cout << moving_chips(ai) << '\n' << std::flush;
  }
}
