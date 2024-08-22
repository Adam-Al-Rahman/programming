// Copyright 2024 Adam-Al-Rahman
// Q: https://projecteuler.net/problem=6
// Optimal Solution: https://projecteuler.net/overview=0006

#include <cstdint>
#include <iostream>

std::uint64_t sum_square_diff(std::uint64_t number) {
  std::uint64_t sum_square = 0;
  std::uint64_t natural_sum = 0;
  for (int i = 1; i <= number; ++i) {
    natural_sum += i;
    sum_square += (i * i);
  }

  return ((natural_sum * natural_sum) - sum_square);
}

std::uint64_t ssd_optimal(std::uint64_t number) {
  std::uint64_t natural_sum = (number * (number + 1)) / 2;
  std::uint64_t sum_square = ((2 * number + 1) * (number + 1) * number) / 6;

  return ((natural_sum * natural_sum) - sum_square);
}

int main() { std::cout << ssd_optimal(100) << std::endl; }
