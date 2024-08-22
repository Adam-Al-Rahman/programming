/*
 * @question: Pointer
 * @brief: How pointer works
 * @source:
 * @tags: ["cpp/pointer" ]
 * @status: solved
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

/**
RC (Reference Counting): A general memory management technique where the lifespan of an object is controlled by counting
the number of references to it. ARC (Automatic Reference Counting): A specific implementation of reference counting,
primarily used in Objective-C and Swift, where the compiler automatically manages the retain and release operations.
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
