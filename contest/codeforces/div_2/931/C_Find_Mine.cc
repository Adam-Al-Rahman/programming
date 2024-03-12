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

/**
 * # mine: 2 (distinct cells)
 * # queries: 4
 * # mine locate: 1
 */

#include <cstdint>
#include <iostream>

std::int64_t query(std::int64_t x, std::int64_t y) {
  std::cout << "? " << x << ' ' << y << '\n' << std::flush;

  std::int64_t min_distance;
  std::cin >> min_distance;

  return min_distance;
}

void find_mine(std::uint64_t n, std::uint64_t m) {
  // max 4 query allowed
  std::int64_t result_query_1 = query(1, 1);
  std::int64_t result_query_2 = 0;
  std::int64_t result_query_3 = 0;
  std::int64_t result_query_4 = 0;

  // first end coordinate of mine diagonal;
  std::int64_t x1 = 0;
  std::int64_t y1 = 0;

  // second end coordinate of mine diagonal;
  std::int64_t x2 = 0;
  std::int64_t y2 = 0;

  // first coordinate
  if (result_query_1 <= n - 1) {
    x1 = result_query_1 + 1;
    y1 = 1;
    result_query_2 = query(x1, y1);
  } else {
    x1 = n;
    y1 = result_query_1 - n + 2;
    result_query_2 = query(x1, y1);
  }

  // second coordinate
  if (result_query_1 <= m - 1) {
    x2 = 1;
    y2 = result_query_1 + 1;
    result_query_3 = query(x2, y2);
  } else {
    x2 = result_query_1 - m + 2;
    y2 = m;
    result_query_3 = query(x2, y2);
  }

  x1 -= (result_query_2 / 2);
  y1 += (result_query_2 / 2);

  x2 += (result_query_3 / 2);
  y2 -= (result_query_3 / 2);

  result_query_4 = query(x2, y2);

  if (result_query_4 == 0) {
    std::cout << "! " << x2 << ' ' << y2 << '\n' << std::flush;
  } else {
    std::cout << "! " << x1 << ' ' << y1 << '\n' << std::flush;
  }
}

int main() {
  std::uint16_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint64_t n;
    std::cin >> n;

    std::uint64_t m;
    std::cin >> m;

    find_mine(n, m);
  }
}
