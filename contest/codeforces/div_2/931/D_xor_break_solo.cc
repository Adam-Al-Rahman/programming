/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: XOR Break
 *
 * @brief:
 * @source: https://codeforces.com/contest/1934/problem/D1
 * @tags:
 * ["topics/", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <cstdint>
#include <iostream>
#include <vector>

void xor_break(std::uint64_t n, std::uint64_t m) {
  std::uint64_t highest_bit = 0;
  std::uint64_t second_highest_bit = 0;

  for (std::int64_t i = (1LL << 62); i > 0; i >>= 1) {
    if (i & n) {
      if (!highest_bit)
        highest_bit = i;
      else if (!second_highest_bit)
        second_highest_bit = i;
    }
  }

  bool flag = (second_highest_bit &&
               ((m & highest_bit) || (m < 2 * second_highest_bit)));

  if (!flag) {
    std::cout << -1 << '\n';
    return;
  }

  std::vector<std::uint64_t> operations = {n, m ^ second_highest_bit, m};
  if (!(m & highest_bit) && (m & second_highest_bit)) operations = {n, m};

  std::cout << static_cast<std::int64_t>(operations.size() - 1) << '\n';
  for (auto &element : operations) std::cout << element << ' ';
  std::cout << '\n';
}

int main() {
  std::uint32_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint64_t n;
    std::cin >> n;

    std::uint64_t m;
    std::cin >> m;

    xor_break(n, m);
    std::cout << std::flush;
  }
}
