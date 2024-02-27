/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Arya in Grid
 * @brief:
 * @source: https://www.codechef.com/problems/ARYAGRID
 * @tags: ["topics/recursion", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

std::uint64_t arya_grid(std::shared_ptr<std::vector<std::vector<bool>>> visited,
                        std::uint64_t n, std::uint64_t m, std::uint64_t l,
                        std::uint64_t x, std::uint64_t y) {
  std::uint64_t count = 1;

  if (!visited->at(x)[y]) visited->at(x)[y] = true;

  if ((x + l) >= 0 && (x + l < n) && !visited->at(x + l)[y]) {
    count += arya_grid(visited, n, m, l, x + l, y);
  }
  if ((x - l >= 0) && (x - l) < n && !visited->at(x - l)[y]) {
    count += arya_grid(visited, n, m, l, x - l, y);
  }
  if ((y + l) >= 0 && (y + l < m) && !visited->at(x)[y + l]) {
    count += arya_grid(visited, n, m, l, x, y + l);
  }
  if ((y - l >= 0) && (y - l) < m && !visited->at(x)[y - l]) {
    count += arya_grid(visited, n, m, l, x, y - l);
  }

  return count;
}

/**
  std::uint32_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint64_t n;
    std::uint64_t m;
    std::uint64_t x0;
    std::uint64_t y0;
    std::uint64_t l;
    std::cin >> n >> m >> x0 >> y0 >> l;
    std::shared_ptr<std::vector<std::vector<bool>>> visited =
        std::make_shared<std::vector<std::vector<bool>>>(
            n, std::vector<bool>(m, false));
    std::cout << arya_grid(visited, n, m, l, x0 - 1, y0 - 1) << '\n'
              << std::flush;
  }
    std::shared_ptr<std::vector<std::vector<bool>>> visited =
      std::make_shared<std::vector<std::vector<bool>>>(
          3, std::vector<bool>(4, false));
*/

// 12345 2345 543 345 65
int main() {
  std::uint32_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint64_t n;
    std::uint64_t m;
    std::uint64_t x0;
    std::uint64_t y0;
    std::uint64_t l;
    std::cin >> n >> m >> x0 >> y0 >> l;
    std::shared_ptr<std::vector<std::vector<bool>>> visited =
        std::make_shared<std::vector<std::vector<bool>>>(
            n, std::vector<bool>(m, false));

    std::cout << arya_grid(visited, n, m, l, x0 - 1, y0 - 1) << '\n'
              << std::flush;
  }
}
