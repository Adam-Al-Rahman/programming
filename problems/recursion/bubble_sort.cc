/*
 * @question: Bubble sort
 * @brief: perform bubble sort
 * @source:
 * https://www.geeksforgeeks.org/recursive-bubble-sort/
 * @tags: ["recursion", "algorithms/bubble_sort", "methods/sortings"]
 * @status: solved
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

void bubble_sort(std::shared_ptr<std::vector<std::int16_t>> list, int index = 0,
                 int counter = 0) {
  if (counter == -(list->size() - 1)) return;  // i.e. no swap occurs

  if (index + 1 > (list->size() - 1)) {
    index = 0;  // size - 1; because index starts at 0
    counter = 0;
  }

  if (list->at(index) > list->at(index + 1)) {
    std::swap(list->at(index), list->at(index + 1));
    counter += 1;
  } else {
    counter -= 1;
  }

  return bubble_sort(list, index + 1, counter);
}

int main() {
  std::shared_ptr<std::vector<std::int16_t>> list =
      std::make_shared<std::vector<std::int16_t>>(
          std::initializer_list<std::int16_t>{5, 1, 4, 2, 8});

  bubble_sort(list);

  for (std::int16_t element : *list) {
    std::cout << element << ' ';
  }
}
