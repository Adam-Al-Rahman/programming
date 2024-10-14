// Zero sum array

// You're given a list of integers nums . Write a function that returns a boolean representing
// whether there exists a zero-sum subarray of nums .
//
// A zero-sum subarray is any subarray where all of the values add up to zero. A subarray is any
// contiguous section ofthe array. For the purposes of this problem, a subarray can be as small as
// one element and as long as the original array.

#include <cassert>
#include <vector>

bool zeroSumSubarray(std::vector<int> nums) { return false; }

int main() {
  auto input = {4, 2, -1, -1, 3};
  auto expected = true;
  auto actual = zeroSumSubarray(input);
  assert(expected == actual);
}
