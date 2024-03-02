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

/** using recursion
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

std::vector<std::vector<std::uint64_t>> permutation(
    std::shared_ptr<std::vector<std::uint64_t>> list,
    std::vector<std::uint64_t> result = {}) {
  std::vector<std::vector<std::uint64_t>> permutes;

  if (list->empty()) {
    permutes.push_back(result);
    return permutes;
  }

  for (std::size_t i = 0; i < list->size(); ++i) {
    std::vector<std::uint64_t> current_list = *list;
    std::vector<std::uint64_t> current_result = result;

    current_result.push_back(current_list[i]);
    current_list.erase(current_list.begin() + i);

    std::vector<std::vector<std::uint64_t>> subPerms =
        permutation(std::make_shared<std::vector<std::uint64_t>>(current_list),
                    current_result);
    permutes.insert(permutes.end(), subPerms.begin(), subPerms.end());
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

  for (std::vector<std::uint64_t> &element : possibility) {
    if (std::equal(element.begin(), element.end(), subarray.begin(),
                   subarray.end(),
                   [](const std::uint64_t &a, const std::uint64_t &b) {
                     return a != b;
                   }))
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

*/

#include <cstdint>
#include <iostream>
#include <vector>

std::string find_b(std::vector<std::uint64_t> ci,
                   std::vector<std::uint32_t> qi) {
  return "";
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
