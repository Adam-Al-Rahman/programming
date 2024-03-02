/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Number of functions calls
 * @brief:
 * @source:
 * @tags: ["topics/", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <iostream>

// number of recursion called
static int recursion_calls = 0;

void g(int n) {
  recursion_calls++;
  if (n < 1) return;
  g(n - 1);
  g(n - 3);
}

int main() {
  g(6);
  std::cout << "x: " << recursion_calls;
}
