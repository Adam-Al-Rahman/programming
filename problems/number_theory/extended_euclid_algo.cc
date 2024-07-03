/**
 * Extended Euclidean Algorithm
 * Copyright 2024 Adam-Al-Rahman
 */

#include <cstdint>
#include <iostream>
#include <tuple>

struct eea_eqn {
  std::int32_t x;
  std::int32_t y;
  std::uint32_t gcd;

  explicit eea_eqn(std::int32_t x = 0, std::int32_t y = 0, std::uint32_t gcd = 1) : x(x), y(y), gcd(gcd) {}
};

eea_eqn extended_euclid(std::uint32_t a, std::uint32_t b) {
  std::int32_t x = 1, y = 0;
  std::int32_t x1 = 0, y1 = 0;
  std::uint32_t a1 = a, b1 = b;

  while (b1) {
    std::uint32_t q = a1 / b1;
    std::tie(x, x1) = std::make_tuple(x1, x - (q * x1));
    std::tie(y, y1) = std::make_tuple(y1, y - (q * y1));
    std::tie(a1, b1) = std::make_tuple(b1, a1 - (q * b1));
  }

  return eea_eqn(x, y, a1);
}

int main() {
  std::uint32_t a = 56, b = 98;
  eea_eqn result = extended_euclid(a, b);
  std::cout << "GCD: " << result.gcd << ", x: " << result.x << ", y: " << result.y << std::endl;
  return 0;
}
