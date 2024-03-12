/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question:
 * @brief:
 * @source:
 * @tags: ["topics/bits", "algorithms/", "methods/bits_manipulation"]
 * @status: unsolved
 */

/** bit functions
*
• __builtin_clz(x): the number of zeros at the beginning of the number
• __builtin_ctz(x): the number of zeros at the end of the number
• __builtin_popcount(x): the number of ones in the number
• __builtin_parity(x): the parity (even or odd) of the number of ones
*
*/

#include <cstdint>
#include <iostream>

int main() {
  std::int32_t x = 5328;  // 00000000000000000001010011010000

  std::cout << __builtin_clz(x) << "\n";       // 19
  std::cout << __builtin_ctz(x) << "\n";       // 4
  std::cout << __builtin_popcount(x) << "\n";  // 5
  std::cout << __builtin_parity(x) << "\n";    // 1
}
