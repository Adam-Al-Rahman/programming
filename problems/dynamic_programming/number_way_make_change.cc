// Number of ways to make change

// Given an array of distinct positive integers representing coin denominations and a single non-
// negative integer n representing a target amount of money, write a function that returns the
// number of ways to make change for that target amount using the given coin denominations.
// Note that an unlimited amount of coins is at your disposal.

#include <cassert>
#include <vector>

int numberOfWaysToMakeChange(int n, std::vector<int> denoms) {
  std::vector<int> ways(n + 1, 0);
  ways[0] = 1;

  for (int i = 0; i < denoms.size(); ++i) {
    for (int amt = 1; amt < ways.size(); ++amt) {
      if (denoms[i] <= amt) ways[amt] += ways[amt - denoms[i]];
    }
  }

  return ways[n];
}

int main() { assert(numberOfWaysToMakeChange(6, {1, 5}) == 2); }
