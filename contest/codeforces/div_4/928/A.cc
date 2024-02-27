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

#include <iostream>
#include <string>

char vlad_best_five(const std::string &str) {
  std::uint16_t count_a = 0;
  std::uint16_t count_b = 0;

  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'A')
      count_a++;
    else
      count_b++;
  }

  if (count_a > count_b) return 'A';
  return 'B';
}

int main() {
  std::int16_t tests;
  std::cin >> tests;

  while (tests--) {
    std::string str;
    std::cin >> str;

    std::cout << vlad_best_five(str) << '\n' << std::flush;
  }
}
