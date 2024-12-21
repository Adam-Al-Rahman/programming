// Sort Stack

// Write a function that takes in an array of integers representing a stack, recursively sorts the stack
// in place (i.e., doesn't create a brand new array), and returns it.

// The array must be treated as a stack, with the end of the array as the top of the stack. Therefore,
// you're only allowed to

// • Pop elements from the top of the stack by removing elements from the end of the array
// using the built-in . pop() method in your programming language of choice.
// • Push elements to the top of the stack by appending elements to the end of the array using
// the built-in . append() method in your programming language of choice.
// • Peek at the element on top of the stack by accessing the last element in the array.

// You're not allowed to perform any other operations on the input array, including accessing
// elements (except for the last element), moving elements, etc.. You're also not allowed to use any
// other data structures, and your solution must be recursive.

#include <cassert>
#include <vector>

void insertInSortedStackOrder(std::vector<int>& stack, int value) {
  if (stack.size() == 0 || stack.back() <= value) {
    stack.push_back(value);
    return;
  }

  int top = stack.back();
  stack.pop_back();

  insertInSortedStackOrder(stack, value);

  stack.push_back(top);
}

std::vector<int> sortStack(std::vector<int>& stack) {
  if (stack.size() == 0) return stack;

  int top = stack.back();
  stack.pop_back();

  sortStack(stack);

  insertInSortedStackOrder(stack, top);

  return stack;
}

int main() {
  std::vector<int> input = {-5, 2, -2, 4, 3, 1};
  std::vector<int> expected = {-5, -2, 1, 2, 3, 4};
  auto actual = sortStack(input);
  assert(expected == actual);
}
