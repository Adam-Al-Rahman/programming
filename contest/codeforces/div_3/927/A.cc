/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Thorns and coins
 * @brief:
 * @source:
 * @tags: ["topics/loop", "algorithms/greedy", "methods/"]
 * @status: solved
 */

// one move: one or two cells, destination cell does not contain throns
// move on a coin cell pick the coin
// tasks:
// - collect maximum coins

#include <iostream>
#include <string>

std::uint16_t throns_coins(std::string cells) {
  std::uint16_t num_coins = 0;

  std::uint16_t i = 1;
  while (i < cells.size()) {
    if (cells[i] == '@') {
      num_coins++;
      i++;
    } else if (cells[i] == '.') {
      i++;
    } else if (cells[i] == '*' && cells[i + 1] != '*') {
      i++;
    } else {
      return num_coins;
    }
  }

  return num_coins;
}

int main() {
  std::uint16_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint16_t n;
    std::cin >> n;

    std::string cells;
    std::cin >> cells;
    std::cout << throns_coins(cells) << '\n' << std::flush;
  }
}
