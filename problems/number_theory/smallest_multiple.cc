// Copyright 2024 Adam-Al-Rahman
// Q: https://projecteuler.net/problem=5

#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>

std::vector<std::uint64_t> get_all_primes(const std::uint64_t& number) {
  std::vector<std::uint64_t> prime_numbers;

  std::vector<bool> is_prime(number + 1, true);
  for (std::uint64_t i = 2; i <= number; ++i) {
    if (is_prime[i]) {
      prime_numbers.push_back(i);
      for (std::uint64_t j = i * i; j <= number; j += i) is_prime[i] = false;
    }
  }

  return prime_numbers;
}

std::uint64_t smallest_multiple(const std::tuple<std::uint16_t, std::uint16_t>& range) {
  auto [start, end] = range;
  std::uint64_t smallest_number = 1;

  for (int i = start; i <= end; ++i) smallest_number = std::lcm(smallest_number, i);

  return smallest_number;
}

int main() { std::cout << smallest_multiple({1, 20}) << std::endl; }
