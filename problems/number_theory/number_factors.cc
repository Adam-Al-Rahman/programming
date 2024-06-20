
/**
 * Number Factors
 * Copyright 2024 Adam-Al-Rahman
 */
#include <iostream>
#include <vector>

std::vector<std::uint32_t> get_factors(std::uint32_t&& number) {
  std::vector<std::uint32_t> factors;

  for (int i = 1; i * i <= number; i++) {
    if (number % i == 0) {
      factors.push_back(i);
      if (i != (number / i)) factors.push_back(number / i);
    }
  }

  return factors;
}

int main() {
  for (auto& val : get_factors(10)) {
    std::cout << val << ' ';
  }
}
