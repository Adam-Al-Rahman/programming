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

#include <cstdint>
#include <iostream>
#include <vector>

std::string rudolf_121(std::vector<std::uint64_t> ai) {
  int ai_size = ai.size();
  ai.push_back(0);
  ai.push_back(0);

  bool make_zero = true;
  for (int i = 0; i < ai_size; i++) {
    if (ai[i + 1] >= (2 * ai[i]) && ai[i + 2] >= ai[i]) {
      ai[i + 1] -= (2 * ai[i]);
      ai[i + 2] -= ai[i];  // why this?
    } else {
      make_zero = false;
      break;
    }
  }

  return (make_zero ? "YES" : "NO");
}

int main() {
  std::uint32_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint64_t n;
    std::cin >> n;

    std::vector<std::uint64_t> ai(n);
    for (std::uint64_t &element : ai) {
      std::cin >> element;
    }

    std::cout << rudolf_121(ai) << '\n' << std::flush;
  }
}
