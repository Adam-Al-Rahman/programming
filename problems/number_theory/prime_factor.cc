/**
 * Prime Factorization
 * Copyright 2024 Adam-Al-Rahman
 */

#include <iostream>
#include <vector>

// Time Complexity: O(sqrt(n))
std::vector<std::uint32_t> prime_factors(int&& number) {
  std::vector<std::uint32_t> prime_factors;

  for (int i = 2; i * i <= number; i++) {
    while (number % i == 0) {
      prime_factors.push_back(i);
      number /= i;
    }
  }
  if (number > 1) prime_factors.push_back(number);
  return prime_factors;
}

int main() {
  for (auto& val : prime_factors(21)) {
    std::cout << val << ' ';
  }
}
