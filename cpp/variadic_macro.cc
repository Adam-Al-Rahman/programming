#include <iostream>

// Define back macro to concatenate two arguments
#define back(A, B) A##B

// Define front macro using variadic arguments
#define front(...) front_impl(__VA_ARGS__)

// Define front_impl macro to handle custom arguments
#define front_impl(A, B) back(A, B)

int main() {
  std::cout << front(3, 4) << std::endl;  // Outputs: 34
  return 0;
}
