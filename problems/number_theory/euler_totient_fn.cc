
/**
 * Euler Totient Fn
 * @doc https://cp-algorithms.com/algebra/phi-function.html
 * Copyright 2024 Adam-Al-Rahman
 */

#include <cstdint>
#include <iostream>
#include <vector>

// For single number
int phi(std::uint32_t&& number) {
  std::uint32_t phi = number;

  for (int i = 2; i * i <= number; i++) {
    if (number % i == 0) {
      while (number % i == 0) {
        number /= i;
        phi -= (phi / i);
      }
    }
  }

  if (number > 1) phi -= (phi / number);

  return phi;
}

// Euler's Totient Fn from 1 to n
// O(nlog(log(n)))
std::vector<std::uint32_t> phi_list(std::uint32_t&& number) {
  std::vector<std::uint32_t> phi_list(number + 1);

  for (int i = 0; i <= number; i++) phi_list[i] = i;

  for (int i = 2; i <= number; i++) {
    if (phi_list[i] == i) {
      for (int j = i; j <= number; j += i) {
        phi_list[j] -= (phi_list[j] / i);
      }
    }
  }

  return phi_list;
}

int main() { std::cout << "φ(12): " << phi(12) << std::endl; }
