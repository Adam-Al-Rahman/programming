/**
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

#include <iostream>

int main() {
  int a = 5;

  int b = (a = 10);  // The assignment operator returns the assigned value
  std::cout << "a: " << a << "\n";  // Output: a: 10

  std::cout << "b: " << b << "\n";  // Output: b: 10
}
