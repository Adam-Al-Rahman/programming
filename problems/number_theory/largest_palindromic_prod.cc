// Copyright 2024 Adam-Al-Rahman
// Q: https://projecteuler.net/problem=4

#include <cstdint>
#include <iostream>
#include <tuple>
#include <vector>

// Without converting to string (only for numbers)
bool is_palindrome(std::uint64_t number) {
  std::uint64_t original = number;
  std::uint64_t reversed = 0;

  while (number > 0) {
    std::uint16_t digit = number % 10;
    reversed = (reversed * 10) + digit;
    number /= 10;
  }

  return original == reversed;
}

std::uint64_t largest_panlindromic_product(std::uint64_t digits) {
  std::vector<std::tuple<std::uint64_t, std::uint64_t>> range = {
      {0, 0},         {0, 9},           {91, 99},           {991, 999},           {9991, 9999},
      {99991, 99999}, {999991, 999999}, {9999991, 9999999}, {99999991, 99999999}, {999999991, 999999999},
  };

  auto [min, max] = range[digits];

  std::uint64_t largest_panlindrome = 0;

  for (std::uint64_t i = max; i >= min; --i) {
    for (std::uint64_t j = i; i >= min; --j) {
      std::uint64_t product = i * j;
      if (product <= largest_panlindrome) break;
      if (is_palindrome(product)) largest_panlindrome = product;
    }
  }

  return largest_panlindrome;
}

std::int32_t main() { std::cout << largest_panlindromic_product(3) << '\n'; }
