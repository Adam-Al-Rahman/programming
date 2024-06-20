
/**
 * Sieve Eratosthenes: Get all the primes <= number
 * Copyright 2024 Adam-Al-Rahman
 */

#include <cstdint>
#include <iostream>
#include <vector>

std::vector<std::uint32_t> sieve_eratosthenes(const std::uint32_t& number) {
  std::vector<std::uint32_t> prime_numbers;

  std::vector<bool> is_prime(number + 1, true);
  for (std::uint64_t i = 2; i <= number; i++) {
    if (is_prime[i]) {
      prime_numbers.push_back(i);
      for (std::uint64_t j = i * i; j <= number; j += i) is_prime[j] = false;
    }
  }

  return prime_numbers;
}

int main() {
  for (auto& prime : sieve_eratosthenes(11)) {
    std::cout << prime << ' ';
  }
}
