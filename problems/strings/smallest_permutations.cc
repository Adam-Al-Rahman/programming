/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question:
 * @brief:
 * @source:
 * @tags: ["topics/string", "algorithms/sort", "methods/sorting"]
 * @status: unsolved
 */

#include <algorithm>
#include <iostream>
#include <string>

std::uint64_t smallest_permutations(std::uint64_t number) {
  std::string number_str = std::to_string(number);
  std::sort(number_str.begin(), number_str.end());

  if (number_str[0] == '0') {
    for (char &character : number_str) {
      if (character != '0') {
        std::swap(character, number_str[0]);
        break;
      }
    }
  }

  return std::stoi(number_str);
}

int main() { std::cout << smallest_permutations(20000301) << std::flush; }
