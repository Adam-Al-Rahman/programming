/**
 * Copyright 2024 Adam-Al-Rahman
 */

#include <cstdint>
#include <iostream>

std::uint32_t gcd(std::uint32_t dividend, std::uint32_t divisor) {
  while (divisor != 0) {
    std::uint32_t remainder = dividend % divisor;
    dividend = divisor;
    divisor = remainder;
  }

  return dividend;
}

int main() { std::cout << "GCD(10, 12): " << gcd(10, 12) << '\n'; }
