/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Heap
 *
 *

 * *
 * @brief:
 * @source:
 * @tags: ["topics/", "algorithms/", "methods/"]
 *

 * *
 *
 * @status: unsolved
 */
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {3, -1, 4, -1, 5, -9};

  // Define a custom comparator using a lambda function
  std::function<bool(int, int)> compare = [](int a, int b) {
    return std::abs(a) > std::abs(b);
  };

  // Convert the vector to a max heap
  std::make_heap(vec.begin(), vec.end(), compare);

  // Now, the vector represents a max heap based on absolute values
  for (const auto &element : vec) {
    std::cout << element << " ";
  }

  // To demonstrate the heap property, you can use pop_heap and push_heap
  // std::pop_heap(vec.begin(), vec.end(), compare);
  // vec.pop_back();  // Extract the maximum element

  // Add a new element and re-establish the heap property
  /* vec.push_back(7); */
  /* std::push_heap(vec.begin(), vec.end(), compare); */

  std::cout << "\nAfter popping and pushing:\n";
  for (const auto &element : vec) {
    std::cout << element << " ";
  }

  std::cout << '\n'
            << "2*0 + 1: " << vec[2 * 0 + 1] << '\n'
            << "2*0 + 2: " << vec[2 * 0 + 2] << '\n'
            << "2*1 + 1: " << vec[2 * 1 + 1] << '\n'
            << "2*1 + 2: " << vec[2 * 1 + 2] << '\n'
            << std::flush;
}
