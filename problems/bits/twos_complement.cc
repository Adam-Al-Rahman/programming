/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Two's Complement
 * @brief:
 * @source:
 * @tags: ["topics/bits", "algorithms/", "methods/"]
 * @status: solved
 */

#include <cstdint>
#include <iostream>

int main() {
  // negative value for 64 bit
  std::int64_t neg_64_bit = 0x8000000000000000;
  std::cout << "Neg 64 bit: " << neg_64_bit << '\n' << std::flush;

  // negative value for 32 bit
  std::int32_t neg_32_bit = 0x80000000;
  std::cout << "Neg 32 bit: " << neg_32_bit << '\n' << std::flush;
}
