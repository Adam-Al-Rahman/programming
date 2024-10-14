// Array of Products

// Write a function that takes in a non-empty array of integers and returns an array of the
// same length, where each element in the output array is equal to the product of every
// other number in the input array.

// In other words, the value at `output[i]` is equal to the product of every number in the
// input array other than `input[i]`

// Note that you're expected to solve this problem without using division.

#include <cassert>
#include <vector>

std::vector<int> arrayOfProducts(const std::vector<int>& array) {
  long long int product = 1;
  int zero_count = 0;
  int zero_idx = 0;
  for (int i = 0; i < array.size(); ++i) {
    if (array[i] != 0) product *= array[i];
    if (array[i] == 0) {
      zero_count += 1;
      zero_idx = i;
    }
  }

  std::vector<int> result(array.size(), 0);
  if (zero_count >= 2) return result;
  if (zero_count == 1) {
    result[zero_idx] = product;
    return result;
  }

  for (int i = 0; i < array.size(); i++) result[i] = product / array[i];

  return result;
}

std::vector<int> array_product_optim(const std::vector<int>& array) {
  std::vector<int> result(array.size());

  long long int product = 1;

  // Left Part
  for (int i = 0; i < array.size(); i++) {
    result[i] = product;
    product *= array[i];
  }

  // Right Part
  product = 1;
  for (int i = array.size() - 1; i >= 0; --i) {
    result[i] *= product;
    product *= array[i];
  }

  return result;
}

int main() {
  std::vector<int> input = {5, 1, 4, 2};
  std::vector<int> expected = {8, 40, 10, 20};
  std::vector<int> actual = array_product_optim(input);
  assert(expected == actual);
}
