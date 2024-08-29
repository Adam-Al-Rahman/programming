// Copyright 2024 Adam-Al-Rahman

#include <cmath>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

std::vector<std::uint64_t> sieve_eratosthenes(const std::uint64_t& number) {
  std::vector<std::uint64_t> prime_numbers;

  std::vector<bool> is_prime(number + 1, true);
  for (std::uint64_t i = 2; i <= number; i++) {
    if (is_prime[i]) {
      prime_numbers.push_back(i);
      if (i * i > number) continue;
      for (std::uint64_t j = i * i; j <= number; j += i) is_prime[j] = false;
    }
  }

  return prime_numbers;
}

std::uint64_t summation_prime(std::uint64_t number) {
  std::vector<std::uint64_t> prime_numbers = sieve_eratosthenes(number);

  return std::accumulate(prime_numbers.begin(), prime_numbers.end(), std::uint64_t(0));
}

int main() { std::cout << summation_prime(2'000'000) << std::endl; }
