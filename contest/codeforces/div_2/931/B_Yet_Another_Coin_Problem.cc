/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question:
 * @brief:
 * @source:
 * @tags: ["topics/maths", "algorithms/", "methods/greedy"]
 * @status: solved
 */

/**
Fact 1
: If coins of value 1
, 3
, 6
 and 15
 were only present the greedy logic of selecting the higher valued first would
work.

Reason: We use coins of value one at most 2
 times, coins of value three at most 1
 time, coins of value six at most 2
 times (if it was used 3
 times, it would be better to use two coins 15+3
) But we can't use the coin of value 3
 and both coins of value 6
 simultaneously, because we would prefer just using 15
.
It means that these coins may sum up to 1+1+3+6=11
 or 1+1+6+6=14
 at max. So, we may use the value 15
 greedily, because the remaining part is less than 15
. When we are left with only the values 1
, 3
, and 6
, greedily solving is obviously correct, because each coin is a divisor of the
next coin.

Fact 2
: We don't need more than 2
 ten coins.

Reason: Better to use 2
 fifteen coins instead of 3
 ten coins.

Using the above two facts it can be shown that the answer will have k<3
 ten coin, therefore, answer = min
(answer(n−10∗k)+k
 assuming 1
, 3
, 6
 and 15
 coins are only present).
*/

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

std::uint64_t yet_another_coin_problem(std::uint64_t n) {
  std::vector<std::uint16_t> triangular_numbers = {1, 3, 6, 10, 15};
  std::uint64_t val = 0;

  // 15
  val += n / 15;
  n %= 15;

  // 6
  val += n / 6;
  n %= 6;

  // 3
  val += n / 3;
  n %= 3;

  // 1
  val += n;

  return val;
}

int main() {
  std::uint32_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint64_t n;
    std::cin >> n;

    if (n < 10) {
      std::cout << yet_another_coin_problem(n) << std::endl;
    } else if (n < 20) {
      std::cout << std::min(yet_another_coin_problem(n),
                            yet_another_coin_problem(n - 10) + 1)
                << std::endl;
    } else {
      std::cout << std::min({yet_another_coin_problem(n),
                             yet_another_coin_problem(n - 10) + 1,
                             yet_another_coin_problem(n - 20) + 2})
                << std::endl;
    }
  }
}
