// Merge Overlapping Intervals

// Write a function that takes in a non-empty array of arbitrary intervals, merges any overlapping
// intervals, and returns the new intervals in no particular order.

// Each interval interval is an array of two integers, with interval [0] as the start of the
// interval and interval [1] as the end of the interval.

// Note that back-to-back intervals aren't considered to be overlapping. For example, [1, 5] and
// [6, 7] aren't overlapping; however, [1, 6] and [6, 7] are indeed overlapping.

// Also note that the start of any particular interval will always be less than or equal to the end of that interval.

#include <algorithm>
#include <cassert>
#include <vector>

std::vector<std::vector<int>> mergeOverlappingIntervals(std::vector<std::vector<int>> intervals) {
  std::sort(intervals.begin(), intervals.end());

  std::vector<std::vector<int>> merge_intervals;
  merge_intervals.push_back(intervals[0]);

  for (int i = 1; i < intervals.size(); ++i) {
    std::vector<int>& alpha = merge_intervals.back();
    std::vector<int> beta = intervals[i];

    if (alpha[1] >= beta[0])
      alpha[1] = std::max(alpha[1], beta[1]);
    else
      merge_intervals.push_back(intervals[i]);
  }

  return merge_intervals;
}

int main() {
  std::vector<std::vector<int>> intervals = {{1, 2}, {3, 5}, {4, 7}, {6, 8}, {9, 10}};
  std::vector<std::vector<int>> expected = {{1, 2}, {3, 8}, {9, 10}};
  auto actual = mergeOverlappingIntervals(intervals);
  assert(expected == actual);
}
