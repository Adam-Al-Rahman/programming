/*
 * @question: Pointer
 * @brief: How pointer works
 * @source:
 * @tags: ["cpp/pointer" ]
 * @status: solved
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

#include <iostream>

int main() {
  int x = 5;
  // to store the address of x we use pointer type variable
  // int ptr != int

  int *x_memory_address = &x;

  // x_memory_address return address of x
  // *x_memory_address return value of x (*: dereferencing operator)

  std::cout << "Hello world";
}
