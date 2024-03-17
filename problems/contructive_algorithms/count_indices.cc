/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Count Indices
 * @brief: Given an array arr[] of N positive integers, the task is to find the
 * count of indices i such that all the elements from arr[0] to arr[i – 1] are
 * smaller than arr[i].
 * @source: Given an array arr[] of N positive integers, the task is to find the
 * count of indices i such that all the elements from arr[0] to arr[i – 1] are
 * smaller than arr[i].
 * @tags: ["topics/contructive_algorithms", "algorithms/", "methods/"]
 * @status: solved
 */

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <iterator>

// array pass by value: std::int16_t list[]
// array pass by ref: const std::int16_t (&list)[list_size]
// array pass by pointer: std::int16_t *list
// RECOMMENDED(array): pass by pointer

template <std::size_t list_size>
std::uint16_t count_indices(const std::int16_t (&list)[list_size]) {
  std::uint16_t index = 1;

  while (index < list_size) {
    if (list[index - 1] > list[index]) {
      index = index - 1;
      break;
    }
    index++;
  }

  return index;
}

int main() {
  std::int16_t list[] = {1, 2, 4, 3};

  std::cout << "List Index: " << count_indices<std::size(list)>(list)
            << std::flush;
}
