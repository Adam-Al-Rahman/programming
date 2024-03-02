/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Turtle Fingers
 * @brief:
 * @source:
 * @tags: ["topics/", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

std::uint16_t turtle_fingers(const std::uint16_t &a, const std::uint16_t &b,
                             const std::uint32_t &l,
                             std::vector<std::vector<std::int16_t>> &possible,
                             std::uint16_t x = 0, std::uint16_t y = 0) {
  std::uint16_t ax = std::pow(a, x);
  std::uint16_t by = std::pow(b, y);

  if (possible[x][y] != -1) {
    return possible[x][y];
  }

  if (l % (ax * by) == 0) {
    return possible[x][y] = 1;
  }

  if (l % (ax * by) != 0) {
    return possible[x][y] = 0;
  }

  std::uint16_t left = turtle_fingers(a, b, l, possible, x + 1, y);
  x = x - 1;
  std::uint16_t right = turtle_fingers(a, b, l, possible, x, y + 1);
  y = y - 1;

  return left + right;
}

int main() {
  std::uint32_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint16_t a;  // 2 <= a, b <= 100
    std::uint16_t b;
    std::uint32_t l;  // 1 <= l <= 10^{6}

    std::cin >> a >> b >> l;

    std::cout << "prev" << std::flush;

    std::vector<std::vector<std::int16_t>> possible(
        std::numeric_limits<std::uint16_t>::max(),
        std::vector<std::int16_t>(std::numeric_limits<std::uint16_t>::max(),
                                  -1));
    std::cout << "after" << std::flush;
    std::cout << turtle_fingers(a, b, l, possible) << '\n' << std::flush;
  }
}
