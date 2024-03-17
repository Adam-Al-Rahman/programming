/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Even | Odd
 * @brief: Check if a number is odd or even using bitwise operators
 * @source:
 * https://www.geeksforgeeks.org/check-if-a-number-is-odd-or-even-using-bitwise-operators/
 * @tags: ["topics/bits", "algorithms/", "methods/bits_manipulation"]
 * @status: solved
 */

#include <cstdint>
#include <iostream>

bool is_even(std::uint16_t number) { return (number & 1) == 0; }

int main() {
  std::uint16_t number = 11;
  std::cout << "The " << number << ' ' << (is_even(number) ? "EVEN" : "ODD")
            << std::flush;
}
