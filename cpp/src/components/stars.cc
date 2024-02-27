#include <cmath>
#include <iostream>

const int valuex(int value) {
  if (value == 0) return 0;
  return (value % 10) + valuex(value / 10);
}
const int integer_digit(int value) { return floor(log10(value) + 1); }

int main() {
  int value{};
  std::cin >> value;

  // int value_sum{};
  // while (value != 0) {
  //   value_sum += value % 10;
  //   value /= 10;
  // }
  // std::cout << value_sum;
  std::cout << integer_digit(value);
}

/*
  // char asterisk{'*'};

  // int test_cases{};
  // std::cin >> test_cases;
  // while (test_cases--) {
  //   int rows;
  //   std::cin >> rows;

  //   for (int i = 0; i < rows; i++) {
  //     for (int j = 0; j <= i; j++) {
  //       std::cout << asterisk;
  //     }
  //     std::cout << "\n";
  //   }
  // }

  // int value{};
  // while (1) {
  //   std::cin >> value;
  //   if (value == 42)
  //     break;
  //   std::cout << value;
  // }
*/
