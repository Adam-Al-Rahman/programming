/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Possibility bits
 * @brief: using a 32 bit single integer variable store 32 flags Possibility
 * @source:
 * @tags: ["topics/bits", "algorithms/bit_manipulation", "methods/"]
 * @status: solved
 */

#include <cstdint>
#include <iostream>

#define FIRST_FLAG 0x01

int main() {
  std::uint32_t flags = FIRST_FLAG | 0x02 | 0x20;
  // std::bitset<32> flags(0x01 | 0x02 | 0x20);

  if (flags & FIRST_FLAG) {
    std::cout << "1st feature is enabled" << '\n' << std::flush;
  }

  if (flags & 2) {
    std::cout << "2nd feature is enabled" << '\n' << std::flush;
  }

  if (flags & 8) {
    std::cout << "8th feature is enabled" << '\n' << std::flush;
  } else {
    std::cout << "8th feature is [disabled]" << '\n' << std::flush;
  }

  if (flags & 32) {
    std::cout << "32nd feature is enabled" << '\n' << std::flush;
  }
}
