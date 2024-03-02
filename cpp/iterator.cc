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

#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

void iterator() {
  std::vector<std::uint16_t> values = {1, 2, 3, 4, 5};
  std::vector<std::uint16_t>::iterator values_it = values.begin();

  for (; values_it != values.end(); values_it++) {
    std::cout << *values_it;
  }

  // structure bindings
  std::unordered_map<std::string, int> map = {{"Machine", 0}, {"Learning", 1}};
  for (auto& [key, value] : map) {  // prefered auto don't use explicit type
    std::cout << "K: " << key << " V: " << value << std::endl;
  }

  // it  = it + 1; it is not recommended instead use,
  // it++ or ++it; recommended
}

int main() {}
