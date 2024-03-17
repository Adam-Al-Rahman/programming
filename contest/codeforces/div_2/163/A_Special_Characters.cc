/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Special Characters
 * @brief:
 * @source:
 * @tags: ["topics/", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <cstdint>
#include <iostream>
#include <string>

void special_characters(std::uint16_t n) {
  std::string str;
  if (n & 1) {
    std::cout << "NO" << '\n' << std::flush;
    return;
  }

  for (std::uint16_t i = 1; i <= (n / 2); i++) {
    if (i == 1)
      str += "AA";
    else
      str += "BAA";
  }

  std::cout << "YES" << '\n' << std::flush;
  std::cout << str << '\n' << std::flush;
}

int main() {
  std::uint16_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint16_t n;
    std::cin >> n;

    special_characters(n);
  }
}
