/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Permuations
 * @brief: Write a function that take unique integers and returns an array of
 * all permuations of those integers in no particular order
 * @source:
 * @tags: ["topics/recursion", "algorithms/", "methods/backtracking"]
 * @status: unsolved
 */

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

std::vector<std::vector<std::int32_t>> get_permutations(std::vector<std::int32_t> list, std::uint32_t index = 0) {
  if (index == (list.size() - 1)) return {list};

  std::vector<std::vector<std::int32_t>> permutation;

  for (int i = index; i < list.size(); i++) {
    std::swap(list[index], list[i]);
    std::vector<std::vector<std::int32_t>> current = get_permutations(list, index + 1);
    permutation.insert(permutation.end(), current.begin(), current.end());
    std::swap(list[index], list[i]);  // backtrack
  }

  return permutation;
}

// use deque
std::vector<std::vector<std::int32_t>> permutations(std::vector<std::int32_t> list,
                                                    std::vector<std::int32_t> current_result = {}) {
  if (list.size() == 1) {
    current_result.push_back(list[0]);
    return {current_result};
  }

  std::vector<std::vector<std::int32_t>> permutation;

  for (int i = 0; i < list.size(); i++) {
    std::int32_t element = list[i];
    current_result.push_back(element);
    list.erase(list.begin() + i);
    std::vector<std::vector<std::int32_t>> current_permutation = permutations(list, current_result);
    current_result.pop_back();
    list.insert(list.begin() + i, element);
    permutation.insert(permutation.end(), current_permutation.begin(), current_permutation.end());
  }
  return permutation;
}

int main() {
  std::vector<std::int32_t> list = {1, 2, 3, 4};

  std::cout << "{ " << std::flush;
  for (std::vector<std::int32_t> sub_list : permutations(list)) {
    std::cout << "{ " << std::flush;
    for (std::int32_t element : sub_list) {
      std::cout << element << ' ';
    }
    std::cout << "}, " << std::flush;
  }
  std::cout << "}" << std::flush;
}
