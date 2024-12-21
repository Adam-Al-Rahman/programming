// Longest Subarray With Sum

// Write a function that takes in a non-empty array of non-negative integers and a non-negative
// integer representing a target sum. The function should find the longest subarray where the
// values collectively sum up to equal the target sum. Return an array containing the starting index
// and ending index of this subarray, both inclusive.

// If there is no subarray that sums up to the target sum, the function should return an empty
// array. You can assume that the given inputs will only ever have one answer.

#include <cassert>
#include <vector>

std::vector<int> longestSubarrayWithSum(std::vector<int> array, int targetSum) {
  std::vector<int> indices;
  int current_sum = 0;

  int start = 0;
  int end = 0;

  while (end < array.size()) {
    current_sum += array[end];
    while (start < end && current_sum > targetSum) {
      current_sum -= array[start];
      start += 1;
    }

    if (current_sum == targetSum) {
      if (indices.empty() || indices[1] - indices[0] < end - start) indices = {start, end};
    }

    end += 1;
  }

  return indices;
}

int main() {
  std::vector<int> array = {1, 2, 3, 4, 3, 3, 1, 2, 1};
  int targetSum = 10;
  std::vector<int> expected = {4, 8};
  auto actual = longestSubarrayWithSum(array, targetSum);
  assert(expected == actual);
}
