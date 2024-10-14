// Copyright 2024 Adam-Al-Rahman

// Smallest Difference

// Write a function that takes in two non-empty arrays of integers, finds the pair of
// numbers (one from each array) whose absolute difference is closest to zero, and
// returns an array containing these two numbers, with the number from the first
// array in the first position.
// Note that the absolute difference of two integers is the distance between them on
// the real number line. For example, the absolute difference of -5 and 5 is 10, and
// the absolute difference of -5 and -4 is 1.
// You can assume that there will only be one pair of numbers with the smallest difference.

#include <algorithm>
#include <cassert>
#include <cmath>
#include <limits>
#include <vector>

std::vector<int> smallestDifference(std::vector<int> a, std::vector<int> b) {
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  int global_diff = std::numeric_limits<int>::max();
  std::vector<int> elements(2, 0);

  int i = 0;
  int j = 0;
  while (i < a.size() && j < b.size()) {
    int diff = std::abs(a[i] - b[j]);

    if (diff < global_diff) {
      global_diff = diff;
      elements[0] = a[i];
      elements[1] = b[j];
    }

    if (a[i] == b[j]) {
      global_diff = diff;
      elements[0] = a[i];
      elements[1] = b[j];
      break;
    } else if (a[i] < b[j]) {
      i += 1;
    } else if (a[i] > b[j]) {
      j += 1;
    }
  }

  return elements;
}

int main() {
  std::vector<int> expected{28, 26};
  assert(smallestDifference({-1, 5, 10, 20, 28, 3}, {26, 134, 135, 15, 17}) == expected);
}
