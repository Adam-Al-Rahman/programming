/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Gray to binary
 * @brief: Convert gray to binary
 * @source:
 * https://www.geeksforgeeks.org/gray-to-binary-and-binary-to-gray-conversion/
 * @tags: ["topics/bits", "algorithms/", "methods/bit_manipulation"]
 * @status: unsolved
 */

/** Gray code
 *
Binary Number is the default way to store numbers, but in many applications,
binary numbers are difficult to use and a variety of binary numbers is needed.
This is where Gray codes are very useful.

Gray code has a property that two successive numbers differ in only one bit
because of this property gray code does the cycling through various states with
minimal effort and is used in K-maps, error correction, communication, etc.
 *
*/

#include <iostream>
#include <string>

// binary to gray code
std::string bin_gray(const std::string &binary) {
  std::string gray_code;
  char prev_bit;

  for (const char &bit : binary) {
    gray_code += (prev_bit == bit) ? '0' : '1';
    prev_bit = bit;
  }

  return gray_code;
}

// gray to binary code
std::string gray_bin(const std::string &gray_code) {
  std::string binary;
  char prev_bit = '0';

  for (const char &bit : gray_code) {
    binary += (prev_bit == bit) ? '0' : '1';
    prev_bit = binary.back();
  }

  return binary;
}

int main() {
  std::string binary = "0011";
  std::cout << "Gray code (" << binary << "): " << bin_gray(binary) << '\n'
            << std::flush;
}
