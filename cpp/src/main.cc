#include "./components/mixed_type_expression.cpp"
#include "./components/vector.cpp"
#include <iostream>

namespace local {
const int calc(int firstNum, int secondNum, char opt);
const bool armstrong(int number);

} // namespace local

int main() {

  // int firstNum, secondNum;
  // char optr;

  // std::cout << "Enter [first_operand operator second_operand]: ";
  // std::cin >> firstNum >> optr >> secondNum;

  // std::cout << local::calc(firstNum, secondNum, optr);
  static_casting_to_int();
  local::armstrong(132);
}

const int local::calc(int firstNum, int secondNum, char opt) {
  switch (opt) {
  case '+':
    return firstNum + secondNum;
  case '*':
    return firstNum * secondNum;
  case '-':
    return firstNum - secondNum;
  }
  return 0;
}

const bool local::armstrong(int number) {

  int is_armstrong;
  int count;

  while (number != 0) {
    number = number % 10;
    count += 1;
    number /= 10;
  }

  if (is_armstrong == number) {
    return true;
  }

  return false;
}
