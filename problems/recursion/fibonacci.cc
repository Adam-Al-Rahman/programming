/**
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

#include <iostream>

/**
 * @param n: nth fib sequence element
 */
int fibonacci(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;

  // not tail recursion
  return fibonacci(n - 2) + fibonacci(n - 1);  // recurrence relation
  // here the `fibonacci(n-2)` is called first and completed then
  // the right part i.e, `fibonacci(n-1)` is called and completed.
}

int main() { std::cout << fibonacci(7) << std::endl; }
