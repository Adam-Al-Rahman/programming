/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: constexpr
 * @brief: How `constexpr` optimize tasks
 * @source:
 * @tags: ["topics/constexpr", "algorithms/", "methods/"]
 * @status: solved
 */

#include <iostream>

constexpr int fib_c(int n) {
  if (n == 0) return 0;
  if (n == 1 || n == 2) return 1;
  return fib_c(n - 1) + fib_c(n - 2);
}

int main() {
  int fib_val = fib_c(35);
  std::cout << fib_val << std::flush;
}
