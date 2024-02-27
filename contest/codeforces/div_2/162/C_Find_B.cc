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

/** good array (ai)
 * sum(ai) = sum(bi)
 * ai != bi
 * bi > 0
 */

/** tasks
 * given: ci; ci > 0
 * answer q queries. during q_{i}, determine the subarray c_{l_{i}}, c_{l_{i} +
 * 1} ... c_{r_{i}} is good
 */

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

std::vector<std::vector<std::uint64_t>> permutation(
    std::shared_ptr<std::vector<std::uint64_t>> list,
    std::vector<std::uint64_t> result = {}) {
  if (list->size() == 1) {
    result.push_back(list->at(0));
    return {result};
  }

  std::vector<std::vector<std::uint64_t>> permutes;

  for (std::size_t i = 0; i < list->size(); ++i) {
    std::uint64_t element = list->at(i);
    result.push_back(element);
    list->erase(list->begin() + i);

    std::vector<std::vector<std::uint64_t>> left = permutation(list, result);
    permutes.insert(permutes.end(), left.begin(), left.end());

    list->insert(list->begin() + i, element);

    std::vector<std::vector<std::uint64_t>> right = permutation(list, result);
    permutes.insert(permutes.end(), right.begin(), right.end());
    result.pop_back();
  }

  return permutes;
}

std::string find_b(std::vector<std::uint64_t> ci,
                   std::vector<std::uint32_t> qi) {
  std::vector<std::uint64_t> subarray;
  for (int i = qi[0] - 1; i < qi[1]; i++) {
    subarray.push_back(ci[i]);
  }

  std::vector<std::vector<std::uint64_t>> possibility =
      permutation(std::make_shared<std::vector<std::uint64_t>>(subarray));

  std::vector<std::vector<std::uint64_t>>::const_iterator it =
      std::find(possibility.begin(), possibility.end(), subarray);
  if (it != possibility.end()) {
    return "YES";
  }

  return "NO";
}

int main() {
  std::uint16_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint32_t n;
    std::cin >> n;

    std::uint32_t q;
    std::cin >> q;

    std::vector<std::uint64_t> ci(n, 0);
    for (std::uint64_t &element : ci) {
      std::cin >> element;
    }

    std::vector<std::vector<std::uint32_t>> qi(
        q, std::vector<std::uint32_t>(2, 0));
    for (std::vector<std::uint32_t> &element : qi) {
      std::cin >> element[0];
      std::cin >> element[1];
    }

    for (std::vector<std::uint32_t> &element : qi) {
      std::cout << find_b(ci, element) << '\n' << std::flush;
    }
  }
}
