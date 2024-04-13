/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Sorted Squared Array
 * @brief:
 * @source:
 * @tags: ["topics/array", "algorithms/", "methods/"]
 * @status: solved
 */

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> sorted_squared_array(std::vector<int> &array) {
  int index = 0;
  std::for_each(array.begin(), array.end(), [&](int element) {
    array[index] = element * element;
    index++;
  });

  std::sort(array.begin(), array.end());
  return array;
}

int main() {
  std::vector<int> array = {1, 2, 3, 5, 6, 8, 9};
  for (auto &element : sorted_squared_array(array)) {
    std::cout << element << ' ';
  }
}
