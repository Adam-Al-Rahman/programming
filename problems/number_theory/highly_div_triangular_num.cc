// Copyright 2024 Adam-Al-Rahman
// Q: https://projecteuler.net/problem=12

#include <cstdint>
#include <iostream>

// Function to find the first triangular number with more than 'threshold' divisors
std::uint64_t highly_div_triangular_num(std::uint64_t threshold) {
  std::uint64_t index = 1;     // Index to compute triangular numbers
  std::uint64_t number = 0;    // Current triangular number
  std::uint64_t divisors = 0;  // Number of divisors of the current triangular number

  while (true) {
    // Compute the current triangular number
    number += index;

    // Compute the number of divisors of 'number'
    divisors = 0;
    for (std::uint64_t i = 1; i * i <= number; ++i) {
      if (number % i == 0) {
        divisors += 1;
        if (i != number / i) divisors += 1;
      }
    }

    // Return the triangular number with more than 'threshold' divisors
    if (divisors > threshold) return number;

    // Move to the next triangular number
    index += 1;
  }
}

int main() { std::cout << highly_div_triangular_num(500) << std::endl; }
