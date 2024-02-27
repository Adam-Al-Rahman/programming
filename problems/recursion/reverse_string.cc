/*
 * @question: Reverse String
 * @brief: In place reverse the string and number of elements reduced by 1
 * @source:
 * https://www.geeksforgeeks.org/sum-triangle-from-array/
 * @tags:
 * ["recursion", "vector", "string", "in-place"]
 * @status: solved
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

#include <iostream>
#include <memory>
#include <variant>
#include <vector>

void reverse_str(std::shared_ptr<std::vector<char>> str, int left_ptr = 0,
                 std::variant<int, char> right_ptr = 'e') {
  if (std::holds_alternative<char>(right_ptr)) {
    right_ptr = static_cast<int>(str->size() - 1);
  }
  if (left_ptr >= std::get<int>(right_ptr)) return;

  // Swap elements using arithmetic operations
  str->at(left_ptr) =
      static_cast<char>(static_cast<int>(str->at(left_ptr)) +
                        static_cast<int>(str->at(std::get<int>(right_ptr))));

  str->at(std::get<int>(right_ptr)) =
      static_cast<char>(static_cast<int>(str->at(left_ptr)) -
                        static_cast<int>(str->at(std::get<int>(right_ptr))));

  str->at(left_ptr) =
      static_cast<char>(static_cast<int>(str->at(left_ptr)) -
                        static_cast<int>(str->at(std::get<int>(right_ptr))));

  return reverse_str(str, left_ptr + 1, std::get<int>(right_ptr) - 1);
}

int main() {
  std::shared_ptr<std::vector<char>> letters =
      std::make_shared<std::vector<char>>(
          std::vector<char>{'H', 'e', 'l', 'l', 'o'});

  reverse_str(letters);
  std::cout << "Reverse str: ";

  for (const char &letter : *letters) {
    std::cout << letter;
  }
}
