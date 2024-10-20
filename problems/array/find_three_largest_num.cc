// Find Three Largest Numbers

// Write a function that takes in an array of at least three integers and, without sorting the
// input array, returns a sorted array of the three largest integers in the input array.

// The function should return duplicate integers if necessary; for example, it should return
// [10, 10, 12] for an input array of [10, 5, 9, 10, 12]

#include <cassert>
#include <limits>
#include <vector>

std::vector<int> findThreeLargestNumbers(std::vector<int> array) {
  std::vector<int> result(3, std::numeric_limits<int>::min());

  for (int i = 0; i < array.size(); ++i) {
    if (result[2] <= array[i]) {
      result[0] = result[1];
      result[1] = result[2];
      result[2] = array[i];
    } else if (result[1] <= array[i]) {
      result[0] = result[1];
      result[1] = array[i];
    } else if (result[0] <= array[i]) {
      result[0] = array[i];
    }
  }

  return result;
}

int main() {
  std::vector<int> expected{18, 141, 541};
  assert(findThreeLargestNumbers({141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7}) == expected);
}
