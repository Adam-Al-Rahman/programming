/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: XOR Break
 * @brief:
 * @source: https://codeforces.com/contest/1934/problem/D1
 * @tags: ["topics/", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <cstdint>
#include <iostream>

void xor_break(std::uint64_t init_x, std::uint64_t target_x) {
  std::uint64_t y = init_x ^ target_x;

  if ((0 < y < init_x) && (0 < (init_x ^ y) < init_x)) {
    init_x = init_x ^ y;
    std::cout << init_x << ' ' << y << ' ';
  } else {
    std::cout << -1 << '\n' << std::flush;
  }
}

int main() {
  std::uint32_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint64_t m;
    std::cin >> m;

    std::uint64_t n;
    std::cin >> n;

    xor_break(n, m);
  }
}
