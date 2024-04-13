
/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Bits string to bits
 * @brief: How to take inputs as string of bits and convert it real bits
 * @source:
 * @tags: ["topics/bits", "algorithms/", "methods/"]
 * @status: solved
 */

#include <bitset>
#include <iostream>
#include <string>

int main() {
  std::string bin;
  std::cout << "Binary String: ";

  std::cin >> bin;

  // Convert the binary string to integer using std::bitset
  std::bitset<32> bits(bin);

  std::uint32_t value = bits.to_ulong();

  // Check if the binary string is negative (starts with '1')
  bool isNegative = bin.front() == '1';

  if (isNegative) {
    // For negative numbers, perform two's complement
    bits = ~bits;  // Invert all bits
    value =
        -(bits.to_ulong() + 1);  // Add 1 after inverting for two's complement
  } else {
    value = bits.to_ulong();
  }

  std::cout << "Decimal value: " << value << std::endl;
}
