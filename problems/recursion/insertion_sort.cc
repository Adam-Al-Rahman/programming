/*
 * @question: Insertion sort
 * @brief: Sort a list using insertion sort.
 * @source:
 * https://www.geeksforgeeks.org/insertion-sort/
 * @tags: ["recursion", "algorithms/insertion_sort", "methods/sorting"]
 * @status: unsolved
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

#include <iostream>
#include <memory>
#include <vector>

void insertion_sort(std::shared_ptr<std::vector<std::int32_t>> list) {
  return insertion_sort(list);
}

int main() {
  std::shared_ptr<std::vector<std::int32_t>> list =
      std::make_shared<std::vector<std::int32_t>>(
          std::initializer_list<std::int32_t>{12, 11, 13, 5, 6});

  insertion_sort(list);

  for (std::int32_t element : *list) {
    std::cout << element << ' ';
  }
}
