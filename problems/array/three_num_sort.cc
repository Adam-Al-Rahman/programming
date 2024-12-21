// Three Number Sort

// You're given an array of integers and another array of three distinct integers. The first array is
// guaranteed to only contain integers that are in the second array, and the second array
// represents a desired order for the integers in the first array. For example, a second array of
// [x, y, z] represents a desired order of [x, x, ..., x, y, y, ..., z, z, z, ..., z] in the first array.

// Write a function that sorts the first array according to the desired order in the second array.

// The function should perform this in place (i.e., it should mutate the input array), and it shouldn't
// use any auxiliary space (i.e., it should run with constant space: 0(1) space).

// Note that the desired order won't necessarily be ascending or descending and that the first array
// won't necessarily contain all three integers found in the second array—it might only contain one or two.

#include <algorithm>
#include <cassert>
#include <vector>

std::vector<int> threeNumberSort(std::vector<int> array, std::vector<int> order) {
  int first_val = order[0];
  int second_val = order[1];

  int first_idx = 0;
  int second_idx = 0;
  int third_idx = array.size() - 1;

  while (second_idx <= third_idx) {
    int val = array[second_idx];

    if (val == first_val) {
      std::swap(array[first_idx], array[second_idx]);
      first_idx += 1;
      second_idx += 1;
    } else if (val == second_val) {
      second_idx += 1;
    } else {
      std::swap(array[second_idx], array[third_idx]);
      third_idx -= 1;
    }
  }

  return array;
}

int main() {
  std::vector<int> array = {1, 0, 0, -1, -1, 0, 1, 1};
  std::vector<int> order = {0, 1, -1};
  std::vector<int> expected = {0, 0, 0, 1, 1, 1, -1, -1};
  std::vector<int> actual = threeNumberSort(array, order);
  assert(expected == actual);
}
