/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: C. Rudolf and the Ugly String
 * @brief:
 * @source:
 * @tags: ["topics/string", "algorithms/", "methods/sub_string"]
 * @status: unsolved
 */

#include <cstdint>
#include <iostream>
#include <string>

std::uint32_t rudolf_str(std::string str) {
  std::uint32_t min_char = 0;

  for (std::size_t i = 0; i + 2 < str.size(); i++) {
    std::string sub_str = str.substr(i, 3);  // i (inclusive)

    if (sub_str == "map" || sub_str == "pie") {
      min_char += 1;
      i += 2;
    }
  }

  return min_char;
}

int main() {
  std::uint32_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint32_t n;
    std::cin >> n;

    std::string str;
    std::cin >> str;

    std::cout << rudolf_str(str) << '\n' << std::flush;
  }
}
