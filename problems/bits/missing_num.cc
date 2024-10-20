// Missing Numbers

// You're given an unordered list of unique integers nums in the range [1, n] , where n
// represents the length of nums + 2 . This means that two numbers in this range are missing
// from the list.

// Write a function that takes in this list and returns a new list with the two missing numbers,
// sorted numerically.

#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

// TC: O(n), SC: O(n)
std::vector<int> missingNumbers(std::vector<int> nums) {
  if (nums.empty()) return {1, 2};

  std::vector<int> result;

  std::unordered_set<int> in(nums.begin(), nums.end());
  for (int i = 1; i <= nums.size() + 2; ++i) {
    if (in.find(i) == in.end()) result.push_back(i);
  }
  return result;
}

// TC: O(n), SC: O(1)
std::vector<int> missing_numbers_optim(const std::vector<int>& nums) {
  int original_sum = 0;
  for (int i = 1; i <= nums.size() + 2; ++i) original_sum += i;

  int sum = 0;
  for (int i = 0; i < nums.size(); ++i) sum += nums[i];

  int half = (original_sum - sum) / 2;  // Each half has only one element
  int original_left_sum = 0;
  int original_right_sum = 0;
  for (int i = 1; i <= nums.size() + 2; ++i) {
    if (i <= half)
      original_left_sum += i;
    else
      original_right_sum += i;
  }

  int left_sum = 0;
  int right_sum = 0;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] <= half)
      left_sum += nums[i];
    else
      right_sum += nums[i];
  }

  return {original_left_sum - left_sum, original_right_sum - right_sum};
}

// TC: O(n), SC: O(1)
std::vector<int> missing_numbers_bitwise(const std::vector<int>& nums) {
  int solution_xor = 0;
  for (int i = 0; i <= nums.size() + 2; ++i) {  // i = 0: 0^0 cancel-out each other
    solution_xor ^= i;
    if (i < nums.size()) solution_xor ^= nums[i];
  }

  std::vector<int> solution(2, 0);
  int set_bit = solution_xor & -solution_xor;
  for (int i = 0; i <= nums.size() + 2; ++i) {
    if ((i & set_bit) == 0)
      solution[0] ^= i;
    else
      solution[1] ^= i;

    if (i < nums.size()) {
      if ((nums[i] & set_bit) == 0)
        solution[0] ^= nums[i];
      else
        solution[1] ^= nums[i];
    }
  }

  return solution;
}

int main() {
  std::vector<int> input = {4, 5, 1, 3};
  std::vector<int> expected = {2, 6};
  auto actual = missing_numbers_bitwise(input);
  std::cout << actual[0] << actual[1] << '\n';
  assert(expected == actual);
}
