
/**
 * Copyright 2024 Adam-Al-Rahman
 */

/**
The check for number % (i + 2) == 0 is a part of an optimization that reduces the number of iterations required to
determine if a number is prime. This optimization leverages the fact that all primes greater than 3 can be written in
the form of 6K ± 1.
*/

#include <cstdint>
#include <iostream>

constexpr bool is_prime(std::uint32_t&& number) {
  if (number <= 1) return false;
  if (number <= 3) return true;                          // 2 and 3 are prime
  if (number % 2 == 0 || number % 3 == 0) return false;  // Eliminate multiples of 2 and 3

  // Check divisors from 5 to sqrt(number)
  for (std::uint32_t i = 5; i * i <= number; i += 6) {  // std::lcm(2,3) == 6
    if (number % i == 0 || number % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

int main() { std::cout << "Is prime: " << is_prime(11) << std::endl; }
