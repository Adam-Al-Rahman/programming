// Min number of coins for change

// Given an array of positive integers representing coin denominations and a single non-negative
// integer n representing a target amount of money, write a function that returns the smallest
// number of coins needed to make change for (to sum up to) that target amount using the given
// coin denominations.

// Note that you have access to an unlimited amount of coins. In other words, if the denominations
// are [1, 5, 10] , you have access to an unlimited amount of 1 s, 5 s, and 10 s.
// If it's impossible to make change for the target amount, return -1

#include <cassert>
#include <limits>
#include <vector>

namespace px {
constexpr int i32_max = std::numeric_limits<int>::max() - 1;  // -1: overcome overflow
}

int minNumberOfCoinsForChange(int n, std::vector<int> denoms) {
  std::vector<int> cache(n + 1, px::i32_max);
  cache[0] = 0;

  for (const int& denom : denoms) {
    for (int amt = 1; amt <= n; ++amt) {
      if (denom <= amt) cache[amt] = std::min(cache[amt], 1 + cache[amt - denom]);
    }
  }

  return cache[n] != px::i32_max ? cache[n] : -1;
}

int main() {
  std::vector<int> input{1, 5, 10};
  assert(minNumberOfCoinsForChange(7, input) == 3);
}
