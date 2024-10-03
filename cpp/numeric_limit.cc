#include <iostream>
#include <limits>

int main() {
  // Infinity only exist for (float, double, long double)
  float f_infinity = std::numeric_limits<float>::infinity();

  // Max is use for int and float both
  int int_max = std::numeric_limits<int>::max();
  float float_max = std::numeric_limits<float>::max();

  // Min
  int int_min = std::numeric_limits<int>::min();

  std::cout << "FLOAT INFINITY: " << f_infinity << '\n';
  std::cout << "INT MAX: " << int_max << '\n';
  std::cout << "INT MIN: " << int_min << '\n';
  std::cout << "FLOAT MAX: " << float_max << '\n';
}
