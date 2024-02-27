/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: A. Maximise The score
 * @brief:
 * @source:
 * https://codeforces.com/contest/1930/problem/0
 * @tags: ["topics/", "algorithms/", "methods/"]
 * @status: unsolved
 */

/**
- 2n positive integer on whiteboard.
- start score of 0
- move exactly n times

*/

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

std::int32_t maximize_score(
    std::shared_ptr<std::vector<std::uint32_t>> whiteboard, std::int32_t n) {
  if (whiteboard->empty()) return 0;

  // std::min_element return and iterator to the min element position
  // Dereferencing the iterator using the * operator is
  // necessary to get the value at that position

  std::int32_t min_1 =
      *std::min_element(whiteboard->begin(), whiteboard->end());
  whiteboard->erase(std::min_element(whiteboard->begin(), whiteboard->end()));
  std::int32_t min_2 =
      *std::min_element(whiteboard->begin(), whiteboard->end());
  whiteboard->erase(std::min_element(whiteboard->begin(), whiteboard->end()));

  return std::min(min_1, min_2) + maximize_score(whiteboard, n - 1);
}

int main() {
  std::uint16_t test;
  std::cin >> test;

  while (test--) {
    std::uint16_t n;
    std::cin >> n;

    std::vector<std::uint32_t> whiteboard;

    for (int i = 0; i < (2 * n); i++) {
      std::int32_t a;
      std::cin >> a;
      whiteboard.push_back(a);
    }

    std::cout << maximize_score(
                     std::make_shared<std::vector<std::uint32_t>>(whiteboard),
                     n)
              << "\n"
              << std::flush;
  }
}
