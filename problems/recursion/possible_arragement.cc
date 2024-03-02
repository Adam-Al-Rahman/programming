/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Recursion
 * @brief:
 * @source:
 * @tags: ["topics/recursion", "algorithms/", "methods/backtracking"]
 * @status: solved
 */

#include <iostream>
#include <memory>
#include <vector>

std::vector<std::vector<std::uint64_t>> permutation(
    std::shared_ptr<std::vector<std::uint64_t>> list,
    std::vector<std::uint64_t> result = {}) {
  std::vector<std::vector<std::uint64_t>> permutes;

  if (list->size() == 1) {
    result.push_back(list->at(0));
    permutes.push_back(result);
    return permutes;
  }

  for (std::size_t i = 0; i < list->size(); ++i) {
    result.push_back(list->at(i));
    list->erase(list->begin() + i);

    std::vector<std::vector<std::uint64_t>> sub_perms =
        permutation(list, result);
    permutes.insert(permutes.end(), sub_perms.begin(), sub_perms.end());

    list->insert(list->begin() + i, result.back());
    result.pop_back();
  }

  return permutes;
}

int main() {
  std::vector<std::uint64_t> input = {1, 2, 3, 4};
  std::vector<std::vector<std::uint64_t>> result =
      permutation(std::make_shared<std::vector<std::uint64_t>>(input));

  for (const auto& perm : result) {
    for (std::uint64_t num : perm) {
      std::cout << num << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
