/*
 * @question: How char works in cpp?
 * @brief: From a given array form a triangle where at each step the sum is same
 * and number of elements reduced by 1
 * @source:
 * @tags: ["cc/char"]
 * @status: solved
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

/**
The use of integers in the context of char typically refers to the fact that the
char type is fundamentally a numeric type in C++ – it represents small integer
values. Each character in C++ is associated with a numeric code according to the
ASCII (or other character encoding) standard.

In C++, a char is guaranteed to be at least 8 bits, allowing it to represent
values from -128 to 127 for signed characters or 0 to 255 for unsigned
characters. This range is sufficient for encoding characters according to the
ASCII standard, where each character is assigned a unique 7-bit code.
*/

#include <iostream>
int main() {
  char myChar = 'A';  // 'A' has an ASCII value of 65
  // Perform arithmetic operation involving char

  int result = myChar + 1;  // Result is 66 (ASCII value of 'B')
  std::cout << "Result: " << result << std::endl;
  return 0;
}
