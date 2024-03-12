/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: A. Rudolf & the Ticket
 * @brief:
 * @source:
 * @tags: ["topics/", "algorithms/", "methods/"]
 * @status: solved
 */

#include <cstdint>
#include <iostream>
#include <vector>

std::uint16_t rudolf_ticket(std::vector<std::uint16_t> bi,
                            std::vector<std::uint16_t> ci, std::uint16_t k) {
  std::uint16_t number_ways = 0;

  for (std::uint16_t &b : bi) {
    for (std::uint16_t &c : ci) {
      if (b + c <= k) {
        number_ways++;
      }
    }
  }

  return number_ways;
}

int main() {
  std::uint16_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint16_t n;
    std::cin >> n;

    std::uint16_t m;
    std::cin >> m;

    std::uint16_t k;
    std::cin >> k;

    std::vector<std::uint16_t> bi(n);
    for (std::uint16_t &element : bi) {
      std::cin >> element;
    }
    std::vector<std::uint16_t> ci(m);
    for (std::uint16_t &element : ci) {
      std::cin >> element;
    }

    std::cout << rudolf_ticket(bi, ci, k) << '\n' << std::flush;
  }
}
