/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Int bit representation
 * @brief:
 * @source:
 * @tags: ["topics/bits", "algorithms/", "methods/bit_manipulation"]
 * @status: solved
 */

#include <climits>  // for CHAR_BIT
#include <iostream>
#include <string>

template <typename T>
std::uint16_t bit_count() {
  // std::cout << "Type: " << typeid(T).name() << std::flush;
  return (sizeof(T) * CHAR_BIT);
}

std::string int_bit_represent(std::int16_t number) {
  std::uint16_t bit_count = ::bit_count<std::int16_t>();

  std::string number_bits = "";

  for (std::int16_t i = (bit_count - 1); i >= 0; i--) {
    if (number & (1 << i))
      number_bits += '1';
    else
      number_bits += '0';
  }

  return number_bits;
}

int main() {
  std::int16_t number = 7;

  std::cout << "Bit Represent " << number << ": " << int_bit_represent(number)
            << std::flush;
}
