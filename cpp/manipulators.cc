/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: C++ Manipulators
 * @brief: How c++ manipulators works
 * @source:
 * @tags: ["topics/cpp", "algorithms/", "methods/"]
 * @status: solved
 */

#include <iomanip>  // setprecision, fixed, showpoint, left, right, setw
#include <iostream>

// NOTE: std::setprecision, std::fixed, std::left, std::right they are (set and
// forget manipulators), i.e. once you set it all the output field will follow
// it until you unset them.

int main() {
  float pi = 3.141592653;

  // setprecision inlcude before decimal as a digit
  // left -> right
  std::cout << std::setprecision(1) << pi << '\n';  // output: 3
  std::cout << std::setprecision(2) << pi << '\n';  // output: 3.1

  // std::fixed is used to print all digit before decimal point &
  // std::setprecision is used here to print digit after decimal point
  std::cout << std::fixed << std::setprecision(1) << pi << '\n';  // output: 3.1

  // unset std::fixed and std::setprecision
  std::cout << std::setprecision(6);  // default std::setprecision value
  std::cout.unsetf(std::ios::fixed);

  // std::showpoint
  float x = 5;
  std::cout << "without std::showpoint: " << x << '\n';
  std::cout << "with std::showpoint: " << std::showpoint << x << '\n';
}
