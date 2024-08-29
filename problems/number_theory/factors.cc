// Copyright 2024 Adam-Al-Rahman

#include <cstdint>
#include <iostream>
#include <vector>

std::vector<std::uint64_t> factors(std::uint64_t number) {
  std::vector<std::uint64_t> factors;

  // Finding factors using optimized approach
  for (std::uint64_t i = 1; i * i <= number; ++i) {
    if (number % i == 0) {
      factors.push_back(i);
      // Avoid duplication for perfect squares
      if (i != number / i) factors.push_back(number / i);
    }
  }

  return factors;
}

int main() {
  for (auto x : factors(5)) std::cout << x << ' ';
}
