/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Generate all possible elements of string
 * @brief:
 * @source:
 * @tags: ["topics/bits", "algorithms/", "methods/bit_mask"]
 * @status: solved
 */

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

// O(n * 2^n)
std::vector<std::string> possible_elements(std::string str) {
  // std::vector<std::uint16_t> masks = {0b000, 0b001, 0b010, 0b100,
  //                                     0b011, 0b110, 0b101, 0b111};

  std::vector<std::string> possible_elements;
  std::uint16_t str_len = str.size();

  // mask < (1 << n), because 2^n - 1 or std::pow(2, str_len);
  for (std::size_t mask = 0; mask < std::pow(2, str_len); mask++) {
    std::string element = "";
    for (int i = 0; i < str_len; i++) {
      if ((mask & (1 << i))) {  //  != 0
        element += str[i];
      }
    }

    possible_elements.push_back(element);
  }

  return possible_elements;
}

int main() {
  std::string str = "ABCD";

  for (std::string &element : possible_elements(str)) {
    std::cout << element << '\n' << std::flush;
  }
}
