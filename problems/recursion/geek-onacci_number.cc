/*
 * @question: Geek-onacci Number
 * @brief:
 * @source:
 * https://www.geeksforgeeks.org/problems/geek-onacci-number/0
 * @tags: ["recursion"]
 * @status: solved
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

#include <iostream>

std::uint16_t geek_onacci(std::uint16_t a, std::uint16_t b, std::uint16_t c,
                          std::uint16_t n) {
  if (n == 0) return a;
  if (n == 1) return b;
  if (n == 2) return c;

  return geek_onacci(a, b, c, n - 1) + geek_onacci(a, b, c, n - 2) +
         geek_onacci(a, b, c, n - 3);
}

int main() {
  std::uint16_t test;
  std::cin >> test;

  while (test--) {
    std::uint16_t a;
    std::uint16_t b;
    std::uint16_t c;
    std::uint16_t n;

    std::cin >> a >> b >> c >> n;
    std::cout << geek_onacci(a, b, c, n - 1) << '\n' << std::flush;
  }
}
