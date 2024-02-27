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

#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

void lr_remainders(std::vector<std::int32_t> array, std::int32_t m,
                   std::string lr, std::int32_t n) {
  int i = 0;
  while (i < n) {
    std::cout << (std::accumulate(array.begin(), array.end(), 1,
                                  std::multiplies<int>()) %
                  m)
              << ' ';

    if (lr[i] == 'L')
      array.erase(array.begin());
    else
      array.pop_back();

    i++;
  }
}

int main() {
  std::int32_t tests;
  std::cin >> tests;

  while (tests--) {
    std::int32_t n;
    std::int32_t m;

    std::cin >> n >> m;

    std::vector<std::int32_t> array;
    for (int i = 0; i < n; i++) {
      std::int32_t a;
      std::cin >> a;
      array.push_back(a);
    }

    std::string lr;
    std::cin >> lr;

    lr_remainders(array, m, lr, n);
  }
}
