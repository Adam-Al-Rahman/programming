// Kadane's Algorithms

// Write a function that takes in a non-empty array of integers and returns the maximum
// sum that can be obtained by summing up all of the integers in a non-empty subarray of
// the input array. A subarray must only contain adjacent numbers (numbers next to each
// other in the input array).

#include <cassert>
#include <vector>

int kadanesAlgorithm(const std::vector<int>& array) {
  if (array.empty()) return 0;

  int max_sum = array[0];
  int max_sum_ending_here = array[0];

  for (int i = 1; i < array.size(); i++) {
    max_sum_ending_here = std::max(max_sum_ending_here + array[i], array[i]);
    if (max_sum_ending_here > max_sum) max_sum = max_sum_ending_here;
  }

  return max_sum;
}

int main() { assert(kadanesAlgorithm({3, 5, -9, 1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1, -5, 4}) == 19); }
