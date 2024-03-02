/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Signed Int behavior
 * @brief:
 * @source:
 * @tags: ["topics/", "algorithms/", "methods/"]
 * @status: unsolved
 */

/** Explaination
 *
 If you try to store a negative value in an std::uint16_t variable, the
 behavior is well-defined according to the C++ standard. The std::uint16_t
 type is an unsigned 16-bit integer, and it cannot represent negative values.
 If you attempt to store a negative value, the result will be the
 representation of that value modulo 2^n, where n is the number of bits in the
 type (16 in this case).

 Example:
 The value of x will be the result of ( -1 modulo 2^16 ), 16 because uint16_t
 i.e. 16 bit, which is equivalent to 65535
 */

#include <cstdint>
#include <iostream>

int main() {
  std::uint16_t x = 0;

  x = -1;

  std::cout << "Value of x: " << x << std::endl;
}
