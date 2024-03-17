/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Equal Xor
 * @brief:
 * @source: https://codeforces.com/contest/1944/problem/B
 * @tags: ["topics/constructive_algorithms", "algorithms/", "methods/"]
 * @status: solved
 */

// if we don't know n value @compile-time
// std::vector<std::uint16_t> positions_array[n + 1];
// or use std::vector<std::vector<std::uint16_t>> positions(n + 1);

#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

void equal_xor(const std::vector<std::uint16_t> &a, std::uint16_t n,
               std::uint16_t k) {
  std::unordered_map<std::uint16_t, std::vector<std::uint16_t>> positions;

  // element: {all indices where it occurred}
  for (std::int32_t i = 0; i < (2 * n); ++i) {
    positions[a[i]].push_back(i);
  }

  std::vector<std::uint16_t> llist;
  std::vector<std::uint16_t> rlist;

  // add same element in same range in llist and rlist
  // because, x ^ x = 0
  // why 1 to n to search, because this way each half part of a[] will be
  // inserted by sorted in llist and rlist
  for (std::int32_t i = 1; i <= n; ++i) {
    if (positions[i].front() < n && positions[i].back() < n &&
        llist.size() < (2 * k)) {
      llist.push_back(i);
      llist.push_back(i);
    } else if (positions[i].front() >= n && positions[i].back() >= n &&
               rlist.size() < (2 * k)) {
      rlist.push_back(i);
      rlist.push_back(i);
    }
  }

  for (std::int32_t i = 1; i <= n; ++i) {
    // if same elements in same range in llist or rlist
    // skip because we add it before in above loop
    if ((positions[i].front() < n && positions[i].back() < n) ||
        (positions[i].front() >= n && positions[i].back() >= n)) {
      continue;
    }

    // add the remaining to cover the llist and rlist size
    if (llist.size() < (2 * k)) {
      llist.push_back(i);
      rlist.push_back(i);
    }
  }

  // print llist elements
  for (std::uint16_t &element : llist) std::cout << element << ' ';
  std::cout << '\n';

  // print rlist elements
  for (std::uint16_t &element : rlist) std::cout << element << ' ';
  std::cout << std::flush;
}

int main() {
  std::uint16_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint16_t n;
    std::cin >> n;

    std::uint16_t k;
    std::cin >> k;

    std::vector<std::uint16_t> a(2 * n);
    for (std::uint16_t &element : a) {
      std::cin >> element;
    }

    equal_xor(a, n, k);
  }
}
