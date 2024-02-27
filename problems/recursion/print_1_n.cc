/*
 * @question: Print 1 to n
 * @brief: Print 1 to n without using loops
 * @source:
 * https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1
 * @tags: ["recursion", "number"]
 * @status: unsolved
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

#include <iostream>

void print_n(const int &till_print, int start = 0,
             bool parent_recursion_fn = true) {
  if (start > till_print) return;

  if (parent_recursion_fn) std::cout << "[ " << std::flush;

  if (start == till_print)
    std::cout << start << " ]" << std::flush;
  else
    std::cout << start << " " << std::flush;

  print_n(till_print, start + 1, parent_recursion_fn = false);
}

int main() { print_n(10); }
