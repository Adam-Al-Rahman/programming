// Reverse Polish Notation

// You're given a list of string tokens representing a mathematical expression using Reverse
// Polish Notation. Reverse Polish Notation is a notation where operators come after operands,
// instead of between them. For example 2 4 + would evaluate to 6

// Parenthesis are always implicit in Reverse Polish Notation, meaning an expression is evaluated
// from left to right. All of the operators for this problem take two operands, which will always be
// the two values immediately preceding the operator. For example, 18 4 — 7 / would evaluate
// to ((18 - 4) / 7) or 2.

// Write a function that takes this list of tokens and returns the result.Your function should support four operators :
// +, -, *, and /.respectively.

// Division should always be treated as integer division, rounding towards zero. For example,
// 3 / 2 evaluates to 1 and -3 / 2 evaluates to -1 . You can assume the input will always
// be valid Reverse Polish Notation, and it will always result in a valid number. Your code should not
// edit this input list.

#include <cassert>
#include <string>
#include <vector>

bool is_operator(std::string ch) { return ch == "+" || ch == "-" || ch == "*" || ch == "/"; }

int reversePolishNotation(std::vector<std::string> tokens) {
  std::vector<int> stack;

  for (auto& token : tokens) {
    if (is_operator(token)) {
      int n1 = stack.back();
      stack.pop_back();

      int n2 = stack.back();
      stack.pop_back();

      if (token == "+") stack.push_back(n1 + n2);
      if (token == "-") stack.push_back(n2 - n1);
      if (token == "*") stack.push_back(n1 * n2);
      if (token == "/") stack.push_back(n2 / n1);  // check: 0-division
    } else {
      stack.push_back(std::stoi(token));
    }
  }

  return stack.back();
}

int main() {
  std::vector<std::string> input = {"3", "2", "+", "7", "*"};
  int expected = 35;
  auto actual = reversePolishNotation(input);
  assert(expected == actual);
}
