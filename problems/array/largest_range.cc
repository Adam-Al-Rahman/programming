// Largest Range

// Write a function that takes in an array of integers and returns an array of length 2 representing
// the largest range of integers contained in that array.

// The first number in the output array should be the first number in the range, while the second
// number should be the last number in the range.

// A range of numbers is defined as a set of numbers that come right after each other in the set of
// real integers. For instance, the output array [2, 6] represents the range {2, 3, 4, 5, 6}
// which is a range of length 5. Note that numbers don't need to be sorted or adjacent in the input
// array in order to form a range.

// You can assume that there will only be one largest range.

#include <cassert>
#include <unordered_map>
#include <vector>

std::vector<int> largestRange(std::vector<int> array) {
  std::vector<int> bestRange = {};
  int longestLength = 0;

  std::unordered_map<int, bool> nums = {};
  for (int num : array) nums[num] = true;

  for (int num : array) {
    if (!nums[num]) continue;

    nums[num] = false;

    int currentLength = 1;
    int left = num - 1;
    int right = num + 1;

    while (nums.find(left) != nums.end()) {
      nums[left] = false;
      currentLength += 1;
      left -= 1;
    }

    while (nums.find(right) != nums.end()) {
      nums[right] = false;
      currentLength += 1;
      right += 1;
    }

    if (currentLength > longestLength) {
      longestLength = currentLength;
      bestRange = {left + 1, right - 1};
    }
  }

  return bestRange;
}

int main() {
  std::vector<int> expected{0, 7};
  assert(largestRange({1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6}) == expected);
}
