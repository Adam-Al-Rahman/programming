
/*
 * @copyright
 * Copyright 2024 Adam Al-Rahman
 *
 * @question:
 * @brief:
 * @source:
 * @tags: ["topics/constructive_algorithm", "algorithms/", "methods/"]
 * @status: solved
 */

#include <cstdint>
#include <iostream>
#include <vector>

std::uint32_t mex_game(const std::vector<std::uint32_t> &a,
                       const std::uint32_t &n) {
  std::vector<std::uint32_t> frequency_a(n + 1, 0);

  for (std::int32_t i = 0; i < n; i++) {
    frequency_a[a[i]]++;
  }

  std::uint32_t mex = 0;

  // mex = missing elements
  while (frequency_a[mex]) {
    mex++;
  }

  std::uint32_t count = 0;
  for (std::int32_t i = 0; i < mex; i++) {
    if (frequency_a[i] == 1) count++;
    if (count == 2) {
      mex = i;
      break;
    }
  }

  return mex;
}

int main() {
  std::uint16_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint32_t n;
    std::cin >> n;

    std::vector<std::uint32_t> a(n);
    for (std::uint32_t &element : a) {
      std::cin >> element;
    }

    std::cout << mex_game(a, n) << '\n' << std::flush;
  }
}
