// Copyright 2024 Adam-Al-Rahman

// Non-Constructible Change
// Given an array of positive integers representing the values of coins in your possession,
// write a function that returns the minimum amount of change (the minimum sum of
// money) that you cannot create. The given coins can have any positive integer value and
// aren't necessarily unique (i.e., you can have multiple coins of the same value).
//
// For example, if you're given coins = [1, 2, 5], the minimum amount of change
// that you can't create is 4 . If you're given no coins, the minimum amount of change that
// you can't create is 1 .

#include <algorithm>
#include <cassert>
#include <vector>

int nonConstructibleChange(std::vector<int>& coins) {
  if (coins.size() == 0) return 1;
  std::sort(coins.begin(), coins.end());

  int change = 0;

  for (int i = 0; i < coins.size(); ++i) {
    if (coins[i] > change + 1) return change + 1;
    change += coins[i];
  }

  return change + 1;
}

int main() {
  std::vector<int> input = {5, 7, 1, 1, 2, 3, 22};
  int expected = 20;
  auto actual = nonConstructibleChange(input);
  assert(expected == actual);
}
