// Longest Peak

// Write a function that takes in an array of integers and returns the length of the longest peak in the array.
// A peak is defined as adjacent integers in the array that are strictly increasing until they
// reach a tip (the highest value in the peak), at which point they become strictly decreasing. At least three integers
// are required to form a peak.

// For example, the integers 1, 4, 10, 2 form a peak, but the integers 4, 0 , 10 don't
// and neither do the integers 1, 2, 2, 0 . Similarly, the integers 1, 2, 3 don't form a
// peak because there aren't any strictly decreasing integers after the 3

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int find_lp(int idx, int a_idx, const std::vector<int>& array, int count = 0) {
  if ((a_idx == array.size() - 1 || a_idx == 0) && (array[idx] > array[a_idx])) return count + 1;
  if ((a_idx == array.size() - 1 || a_idx == 0) || (array[idx] <= array[a_idx])) return count;

  if (a_idx > idx)
    return find_lp(a_idx, a_idx + 1, array, count + 1);
  else
    return find_lp(a_idx, a_idx - 1, array, count + 1);
}

int longestPeak(const std::vector<int>& array) {
  if (array.size() < 3) return 0;

  int longest_peak = 0;
  for (int i = 1; i < array.size() - 1; ++i) {
    if (array[i] > array[i - 1] && array[i] > array[i + 1]) {
      longest_peak = std::max(longest_peak, find_lp(i, i - 1, array) + find_lp(i, i + 2, array) + 1);
    }
  }

  return longest_peak;
}

// Recommended
int longest_peak_iterative(const std::vector<int>& array) {
  int longest_peak = 0;
  int i = 1;

  while (i < array.size() - 1) {
    bool is_peak = array[i - 1] < array[i] && array[i] > array[i + 1];
    if (!is_peak) {
      i += 1;
      continue;
    }

    int left_idx = i - 2;
    while (left_idx >= 0 && array[left_idx] < array[left_idx + 1]) left_idx += 1;

    int right_idx = i + 2;
    while (right_idx < array.size() && array[right_idx] < array[right_idx - 1]) right_idx += 1;

    int current_peak_len = right_idx - left_idx - 1;
    longest_peak = std::max(longest_peak, current_peak_len);
    i = right_idx;
  }

  return longest_peak;
}

int main() {
  std::vector<int> input = {1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
  int expected = 6;
  int actual = longest_peak_iterative(input);
  std::cout << actual << std::endl;
  assert(expected == actual);
}
