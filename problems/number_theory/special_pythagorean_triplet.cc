// Copyright 2024 Adam-Al-Rahman
// Q: https://projecteuler.net/problem=9

#include <cstdint>
#include <iostream>

std::uint64_t special_pythagorean_triplet(std::uint64_t product) {
  for (int a = 1; a < 1000; ++a) {
    for (int b = a; b < 500 - (a / 2); ++b) {
      std::uint64_t c = 1000 - a - b;
      if (a * a + b * b == c * c) return a * b * c;
    }
  }

  return 0;
}

int main() { std::cout << special_pythagorean_triplet(1000) << std::endl; }
