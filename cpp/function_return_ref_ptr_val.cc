#include <iostream>

// Function returning a pointer
int *returnPointer(int x) {
  int *ptr = new int(x);
  return ptr;
}

// Function returning a reference
int &returnReference(int &x) {
  x *= 2;
  return x;
}

// Function returning a value
int returnByValue(int x, int y) { return x + y; }

int main() {
  // Example of returning a pointer
  int *ptrResult = returnPointer(5);
  std::cout << "Returned pointer value: " << *ptrResult << std::endl;
  delete ptrResult; // Remember to delete the allocated memory

  // Example of returning a reference
  int originalValue = 10;
  int &referenceResult = returnReference(originalValue);
  std::cout << "Original value after doubling through reference: "
            << originalValue << std::endl;

  // Example of returning a value
  int result = returnByValue(3, 4);
  std::cout << "Returned value: " << result << std::endl;

  return 0;
}
