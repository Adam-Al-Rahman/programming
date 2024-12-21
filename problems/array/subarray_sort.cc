// Subarray Sort

// Write a function that takes in an array of at least two integers and that returns an array of the
// starting and ending indices of the smallest subarray in the input array that needs to be sorted in
// place in order for the entire input array to be sorted (in ascending order).

// If the input array is already sorted, the function should return [—1, -1]

#include <cassert>
#include <climits>
#include <vector>

bool isOutOfOrder(int i, int num, std::vector<int> array) {
  if (i == 0) return num > array[i + 1];

  if (i == array.size() - 1) return num < array[i - 1];

  return num > array[i + 1] || num < array[i - 1];
}

std::vector<int> subarraySort(std::vector<int> array) {
  int minOutOfOrder = INT_MAX;
  int maxOutOfOrder = INT_MIN;

  for (int i = 0; i < array.size(); i++) {
    int num = array[i];
    if (isOutOfOrder(i, num, array)) {
      minOutOfOrder = std::min(minOutOfOrder, num);
      maxOutOfOrder = std::max(maxOutOfOrder, num);
    }
  }

  if (minOutOfOrder == INT_MAX) return std::vector<int>{-1, -1};

  int subarrayLeftIdx = 0;
  while (minOutOfOrder >= array[subarrayLeftIdx]) subarrayLeftIdx += 1;

  int subarrayRightIdx = array.size() - 1;
  while (maxOutOfOrder <= array[subarrayRightIdx]) subarrayRightIdx -= 1;

  return std::vector<int>{subarrayLeftIdx, subarrayRightIdx};
}

int main() {
  std::vector<int> expected{3, 9};
  assert(subarraySort({1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19}) == expected);
}
