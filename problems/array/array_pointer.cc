/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Iterate array using pointer;
 * @brief:
 * @source:
 * @tags: ["topics/array", "algorithms/", "methods/pointer"]
 * @status: solved
 */

#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  std::vector<std::int32_t> a = {1, 2, 3, 4, 5};
  std::int32_t *fast = a.data();

  // Traverse the vector using the pointer fast
  for (std::size_t i = 0; i < a.size(); ++i) {
    std::cout << *fast << " ";  // Print the element pointed to by fast
    ++fast;                     // Move fast to point to the next element
  }

  std::cout << std::endl;
}
