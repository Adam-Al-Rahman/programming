// Next Greater Element

// Write a function that takes in an array of integers and returns a new array containing, at each
// index, the next element in the input array that's greater than the element at that index in the
// input array.

// In other words, your function should return a new array where outputArray[i] is the next. If there's no such next
// greater element in the input array that's greater than inputArray[i] element for a particular index, the value at
// that index in the output array should be -1 . For example, given array [1, 2] , your function should return [2, -1]

// Additionally, your function should treat the input array as a circular array. A circular array wraps
// around itself as if it were connected end-to-end. So the next index after the last index in a
// circular array is the first index. This means that, for our problem, given
// array = [O, 0 , 5, 0 , 0 , 3, 0 , O] , the next greater element after 3 is 5 , since the
// array is circular.

#include <cassert>
#include <vector>

std::vector<int> nextGreaterElement(std::vector<int> array) {
  std::vector<int> result(array.size(), -1);
  std::vector<int> stack;

  for (int i = 0; i < 2 * array.size(); i++) {
    int circularIdx = i % array.size();

    while (stack.size() > 0 && array[stack.back()] < array[circularIdx]) {
      int top = stack.back();
      stack.pop_back();
      result[top] = array[circularIdx];
    }

    stack.push_back(circularIdx);
  }

  return result;
}

int main() {
  std::vector<int> input = {2, 5, -3, -4, 6, 7, 2};
  std::vector<int> expected = {5, 6, 6, 6, 7, -1, 5};
  auto actual = nextGreaterElement(input);
  assert(expected == actual);
}
