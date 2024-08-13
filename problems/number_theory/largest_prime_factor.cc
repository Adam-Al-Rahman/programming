// Copyright 2024 Adam-Al-Rahman
// Q: https://projecteuler.net/problem=3

#include <cstdint>
#include <iostream>

std::uint64_t largest_prime_factor(std::uint64_t number) {
  std::uint64_t largest_prime_factor = 2;

  for (std::uint64_t i = 2; i * i <= number; i++) {
    while (number % i == 0) {
      if (largest_prime_factor < i) largest_prime_factor = i;
      number /= i;
    }
  }

  if (number > 1 && largest_prime_factor < number) largest_prime_factor = number;

  return largest_prime_factor;
}

int main() { std::cout << largest_prime_factor(600851475143) << '\n'; }
