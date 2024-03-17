/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Generate gray code
 * @brief: Given a number N, generate bit patterns from 0 to 2^N-1 such that
 * successive patterns differ by one bit.
 * @source:
 * https://www.geeksforgeeks.org/generate-n-bit-gray-codes/
 * @tags: ["topics/gray_code", "algorithms/", "methods/bit_manipulation"]
 * @status: unsolved
 */

#include <bitset>
#include <climits>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> generate_gray_code(std::uint16_t num_bits) {
  std::vector<std::string> list;

  for (std::size_t i = 0; i < (1LL << num_bits); i++) {
    // Generating the decimal
    // values of gray code then using
    // bitset to convert them to binary form
    std::int32_t gray_code_int = (i ^ (i >> 1));

    std::bitset<sizeof(gray_code_int) * CHAR_BIT> gray_code_bits(gray_code_int);

    // convert to string
    std::uint16_t gray_code_int_num_bits = sizeof(gray_code_int) * CHAR_BIT;
    std::string gray_code_bits_str = gray_code_bits.to_string();
    list.push_back(
        gray_code_bits_str.substr(gray_code_int_num_bits - num_bits));
  }

  return list;
}

int main() {
  for (const std::string &element : generate_gray_code(2)) {
    std::cout << element << ' ';
  }
  std::cout << std::flush;
}
