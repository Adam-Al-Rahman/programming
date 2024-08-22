// Copyright 2024 Adam-Al-Rahman
// Q: https://projecteuler.net/problem=7

#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

// `Pierre Dusart` in his 1999 Ph.D. thesis.
// Dusart's work provided refined estimates for the distribution of prime numbers
std::uint64_t estimate_upper_bound(std::uint64_t n) {
  if (n < 6) return 15;  // small cases
  return n * (std::log(n) + std::log(std::log(n)));
}

std::vector<std::uint64_t> sieve_eratosthenes(const std::uint64_t& number) {
  std::vector<std::uint64_t> prime_numbers;

  std::vector<bool> is_prime(number + 1, true);
  for (std::uint64_t i = 2; i <= number; i++) {
    if (is_prime[i]) {
      prime_numbers.push_back(i);
      for (std::uint64_t j = i * i; j <= number; j += i) is_prime[j] = false;
    }
  }

  return prime_numbers;
}

std::uint64_t nth_prime(std::uint64_t n) {
  std::uint64_t limit = estimate_upper_bound(n);
  std::vector<std::uint64_t> primes = sieve_eratosthenes(limit);
  return primes[n - 1];
}

int main() { std::cout << nth_prime(10001) << std::endl; }
