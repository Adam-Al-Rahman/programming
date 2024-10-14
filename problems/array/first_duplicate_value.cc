// First Duplicate Value

// Given an array of integers between 1 and n , inclusive, where n is the length of the array,
// write a function that returns the first integer that appears more than once (when the array is
// read from left to right).

// In other words, out of all the integers that might occur more than once in the input array, your
// function should return the one whose first duplicate value has the minimum index.
// If no integer appears more than once, your function should return -1 .
// Note that you're allowed to mutate the input array.

// A1: We can use std::unordered_set which has O(1) to find

#include <cassert>
#include <cmath>
#include <vector>

int firstDuplicateValue(std::vector<int>& array) {
  int first_duplicate_value = -1;
  for (int i = 0; i < array.size(); ++i) {
    int idx = std::abs(array[i]) - 1;
    if (array[idx] < 0) {
      first_duplicate_value = std::abs(array[i]);
      break;
    } else {
      array[idx] = -array[idx];
    }
  }

  return first_duplicate_value;
}

int main() {
  std::vector<int> input = {2, 1, 5, 2, 3, 3, 4};
  int expected = 2;
  int actual = firstDuplicateValue(input);
  assert(expected == actual);
}
