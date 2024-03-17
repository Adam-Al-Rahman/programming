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

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

// sort duplicate elements first
std::vector<std::uint16_t> special_sort(
    const std::vector<std::uint16_t> &input) {
  std::vector<std::uint16_t> duplicates, non_duplicates;

  // Separate duplicates and non-duplicates
  for (std::uint16_t num : input) {
    if (std::count(input.begin(), input.end(), num) > 1) {
      duplicates.push_back(num);
    } else {
      non_duplicates.push_back(num);
    }
  }

  // Sort duplicates in ascending order
  std::sort(duplicates.begin(), duplicates.end());

  // Sort non-duplicates in ascending order
  std::sort(non_duplicates.begin(), non_duplicates.end());

  // Merge duplicates and sorted non-duplicates
  std::vector<std::uint16_t> sorted_vec;
  sorted_vec.reserve(duplicates.size() + non_duplicates.size());
  sorted_vec.insert(sorted_vec.end(), duplicates.begin(), duplicates.end());
  sorted_vec.insert(sorted_vec.end(), non_duplicates.begin(),
                    non_duplicates.end());

  return sorted_vec;
}

void equal_xor(const std::vector<std::uint16_t> &a, std::uint16_t n,
               std::uint16_t k) {
  std::vector<std::uint16_t> llist;
  std::vector<std::uint16_t> rlist;

  for (int i = 0; i < n; i++) {
    llist.push_back(a[i]);
    rlist.push_back(a[n + i]);
  }

  // special_sort
  llist = special_sort(llist);
  rlist = special_sort(rlist);

  // print llist elements
  for (int i = 0; i < 2 * k; i++) std::cout << llist[i] << ' ';
  std::cout << '\n';

  // print rlist elements
  for (int i = 0; i < 2 * k; i++) std::cout << rlist[i] << ' ';
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
