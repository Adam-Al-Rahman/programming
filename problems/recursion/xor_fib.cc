/*
 * @question: Xor Fibonacci
 * @brief: fib(n-1) ^ fib(n-2)
 * @source:
 * https://www.codechef.com/problems/FIBXOR01/
 * @tags: ["recursion", "fib", "xor"]
 * @status: unsolved
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

#include <iostream>
#include <memory>
#include <vector>

std::int32_t xor_fib(std::shared_ptr<std::vector<std::int32_t>> memo_vector,
                     const std::uint32_t &a, const std::uint32_t &b,
                     std::uint32_t n) {  // 0<=a,b,n<=10^9
  if (n == 0) return a;
  if (n == 1) return b;

  if (memo_vector->at(n) != -1) return memo_vector->at(n);

  return memo_vector->at(n) = xor_fib(memo_vector, a, b, n - 1) ^
                              xor_fib(memo_vector, a, b, n - 2);
}

int main() {
  //  std::uint16_t tests;  // uint16 because [ unsigned, 1<=test<=10^3 ]
  //  std::cin >> tests;

  std::shared_ptr<std::vector<int32_t>> memo_vector =
      std::make_shared<std::vector<int32_t>>(5 + 1, -1);
  std::cout << xor_fib(memo_vector, 0, 1, 5) << "\n";

  /* while (tests--) { */
  /*   std::uint16_t a; */
  /*   std::uint16_t b; */
  /*   std::uint32_t n; */
  /**/
  /*   std::cin >> a >> b >> n; */
  /**/
  /*   std::shared_ptr<std::vector<int32_t>> memo_vector = */
  /*       std::make_shared<std::vector<int32_t>>(n + 1, -1); */
  /*   std::cout << xor_fib(memo_vector, a, b, n) << "\n"; */
  /* } */
}
