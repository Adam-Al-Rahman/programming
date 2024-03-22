/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Equal Xor
 *
 * @brief:
 * @source: https://codeforces.com/contest/1944/problem/B
 * @tags:
 * ["topics/constructive_algorithms", "algorithms/", "methods/"]
 * @status: solved
 */

// if we don't know n value @compile-time
// std::vector<int> positions_array[n + 1];
// or use std::vector<std::vector<std::uint16_t>> positions(n + 1);

#include <iostream>
#include <vector>

void equal_xor(const std::vector<int> &a, const int &n, const int &k) {
  std::vector<int> element_occurrences(n + 1, 0);

  // Count occurrences of each element
  for (int i = 0; i < n; i++) {
    element_occurrences[a[i]]++;
  }

  // Separate elements based on occurrences
  std::vector<int> zero_occurrences;
  std::vector<int> single_occurrences;
  std::vector<int> double_occurrences;

  for (int i = 1; i <= n; i++) {
    if (element_occurrences[i] == 0)
      zero_occurrences.push_back(i);
    else if (element_occurrences[i] == 1)
      single_occurrences.push_back(i);
    else  // value == 2
      double_occurrences.push_back(i);
  }

  int num_elements = 0;

  // Print l-subset
  for (int &element : double_occurrences) {
    if (num_elements < (2 * k)) {
      num_elements += 2;
      std::cout << element << ' ' << element << ' ';
    }
  }

  for (int &element : single_occurrences) {
    if (num_elements < (2 * k)) {
      num_elements++;
      std::cout << element << ' ' << std::flush;
    }
  }

  std::cout << '\n';

  // Print r-subset
  num_elements = 0;
  for (int &element : zero_occurrences) {
    if (num_elements < (2 * k)) {
      num_elements += 2;
      std::cout << element << ' ' << element << ' ';
    }
  }

  for (int &element : single_occurrences) {
    if (num_elements < (2 * k)) {
      num_elements++;
      std::cout << element << ' ';
    }
  }

  std::cout << '\n' << std::flush;
}

int main() {
  int tests;
  std::cin >> tests;

  while (tests--) {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(2 * n);
    for (int &element : a) {
      std::cin >> element;
    }

    equal_xor(a, n, k);
  }
}
