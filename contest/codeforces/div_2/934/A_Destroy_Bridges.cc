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

#include <cstdint>
#include <iostream>

std::int32_t destroying_bridges(std::uint16_t n, std::uint32_t k) {
  if (k >= (n - 1)) return 1;
  return n;
}

int main() {
  std::uint16_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint16_t n;
    std::cin >> n;

    std::uint32_t k;
    std::cin >> k;

    std::cout << destroying_bridges(n, k) << '\n' << std::flush;
  }
}
