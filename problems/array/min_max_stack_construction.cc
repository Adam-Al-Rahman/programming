// Min Max Stack Construction

// Write a MinMaxStack class for a Min Max Stack. The class should support:
// • Pushing and popping values on and off the stack.
// • Peeking at the value at the top of the stack.
// • Getting both the minimum and the maximum values in the stack at any given point in time.

// All class methods, when considered independently, should run in constant time and with constant space.

#include <algorithm>
#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

#define testMinMaxPeek(min, max, peekValue, stack) \
  {                                                \
    assert(stack.getMin() == min);                 \
    assert(stack.getMax() == max);                 \
    assert(stack.peek() == peekValue);             \
  }

class MinMaxStack {
 public:
  std::vector<std::unordered_map<std::string, int>> minMaxStack = {};
  std::vector<int> stack = {};

  int peek() { return stack[stack.size() - 1]; }

  int pop() {
    minMaxStack.pop_back();
    int result = stack[stack.size() - 1];
    stack.pop_back();
    return result;
  }

  void push(int number) {
    std::unordered_map<std::string, int> newMinMax = {{"min", number}, {"max", number}};

    if (minMaxStack.size()) {
      std::unordered_map<std::string, int> lastMinMax = minMaxStack[minMaxStack.size() - 1];
      newMinMax["min"] = std::min(lastMinMax["min"], number);
      newMinMax["max"] = std::max(lastMinMax["max"], number);
    }

    minMaxStack.push_back(newMinMax);
    stack.push_back(number);
  }

  int getMin() { return minMaxStack[minMaxStack.size() - 1]["min"]; }
  int getMax() { return minMaxStack[minMaxStack.size() - 1]["max"]; }
};

int main() {
  MinMaxStack stack;
  stack.push(5);
  testMinMaxPeek(5, 5, 5, stack);
  stack.push(7);
  testMinMaxPeek(5, 7, 7, stack);
  stack.push(2);
  testMinMaxPeek(2, 7, 2, stack);
  assert(stack.pop() == 2);
  assert(stack.pop() == 7);
  testMinMaxPeek(5, 5, 5, stack);
}
