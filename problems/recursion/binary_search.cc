// Copyright 2024 Adam-Al-Rahman

/**
 The error message "no viable overloaded =" typically means that the compiler
 couldn't find a suitable assignment operator (operator=) for the given types
 involved in the assignment.
*/

#include <iostream>
#include <variant>
#include <vector>

int binary_search(const int &to_search, const std::vector<int> &sorted_list,
                  int left_ptr = 0, std::variant<int, char> right_ptr = 's') {
  // int sorted_list_len = sorted_list.size();

  if (std::holds_alternative<char>(right_ptr)) {
    /* right_ptr = sorted_list.size() - 1; */  // No viable overloaded =,
                                               // because size() method return
                                               // type is std::size_t
    right_ptr = static_cast<int>(sorted_list.size() - 1);
    // right_ptr = sorted_list_len - 1;
  }

  int mid_ptr = ((left_ptr + std::get<int>(right_ptr)) / 2);
  int mid_element = sorted_list[mid_ptr];

  if (mid_element == to_search) return mid_ptr;

  if (to_search <= mid_element) {
    /* left_ptr = left_ptr; */
    right_ptr = mid_ptr - 1;
  }

  if (to_search > mid_element) {
    left_ptr = mid_ptr + 1;
    /* right_ptr = right_ptr; */
  }

  if (left_ptr > std::get<int>(right_ptr)) return -1;  // no element present

  return binary_search(to_search, sorted_list, left_ptr, right_ptr);
}

int main() {
  std::vector<int> sorted_list = {1, 2};
  std::cout << "Index: " << binary_search(2, sorted_list) << std::flush;
}
