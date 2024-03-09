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
 * 1. add reverse string to the `end` of the string.
 */

#include <algorithm>  // std::reverse
#include <cstdint>
#include <iostream>
#include <string>

std::string entertainment_mac(std::uint64_t even_n, std::string str) {
  std::string reverse_str = str;
  std::reverse(reverse_str.begin(), reverse_str.end());  // in place reverse

  return std::min(str, reverse_str + str);
}

int main() {
  std::uint16_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint64_t n;
    std::cin >> n;

    std::string str;
    std::cin >> str;

    std::cout << entertainment_mac(n, str) << '\n' << std::flush;
  }
}
