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

// A traingle or a square drawn (using 1)
// tasks:
// - which shapes it is drawm
// possiblilities: triangle, square
// - triangle: k consecutive rows of 1

#include <iostream>
#include <string>
#include <vector>

std::string vlad_shape(const std::vector<std::string> &shape) {
  for (std::string sub_list : shape) {
    std::uint16_t count = 0;
    for (int i = 0; i < sub_list.size(); i++) {
      if (sub_list[i] == '1') {
        count++;
      }
    }

    if (count != 1)
      count = 0;
    else
      return "TRIANGLE";
  }
  return "SQUARE";
}

int main() {
  std::uint16_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint16_t n;
    std::cin >> n;

    std::vector<std::string> shape;

    for (int i = 0; i < n; i++) {
      std::string a;
      std::cin >> a;
      shape.push_back(a);
    }

    std::cout << vlad_shape(shape) << '\n' << std::flush;
  }
}
