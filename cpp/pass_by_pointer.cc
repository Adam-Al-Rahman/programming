// Copyright 2024 Adam-Al-Rahman
/** Pass by pointer

Pointer Passing by Value:
When you pass a pointer to a function,
you are passing the pointer by value.
This means a copy of the pointer is made and used within the function.
The function can modify the object being pointed to,
but changes to the pointer itself (such as reassigning it)
will not affect the original pointer in the calling function.

Note: `pass-by-pointer` uses `pass-by-value`.

*/

#include <iostream>

void ModifyValue(int* ptr) {
  // Modify the value pointed to by ptr
  *ptr = 42;
  // Change the pointer itself (will not affect original pointer) (because pointer is pass-by-value)
  ptr = nullptr;
}

int main() {
  int value = 10;
  std::cout << "Before: " << value << std::endl;  // Output will be 10

  // Pass the address of value to the function
  ModifyValue(&value);

  std::cout << "After: " << value << std::endl;  // Output will be 42

  return 0;
}
