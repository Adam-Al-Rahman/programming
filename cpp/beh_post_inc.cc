#include <iostream>

int main() {
  int x = 5;      // Source value
  int y_val = 0;  // Destination value

  int* z = &x;      // Pointer to the source variable (z points to x)
  int* y = &y_val;  // Pointer to the destination variable (y points to y_val)

  // Perform the operation: *y++ = *z++
  *y++ = *z++;  // Copies the value of x (5) into y_val

  // Print the results
  std::cout << "x: " << x << std::endl;
  std::cout << "y_val: " << y_val << std::endl;

  // Print the pointers
  std::cout << "y: " << y << "\n";
  std::cout << "z: " << z << "\n";
}
