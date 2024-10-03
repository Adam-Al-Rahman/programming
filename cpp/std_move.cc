// Copyright 2024 Adam-Al-Rahman

#include <iostream>
#include <string>
#include <utility>

/**
_Transferring Pointers_: The move constructor or move assignment operator
transfers the ownership of the internal resources (like pointers to the data)
from the source object to the destination object. This involves assigning pointers and
possibly setting the source object's pointers to nullptr or resetting other internal state variables.

_No Deep Copy_: Unlike a copy operation,
a move operation doesn't involve allocating new memory or copying the actual data,
which makes it much faster.
*/

// NOTE: Once you provide your `destructor` in `class` you loose the `std::move` operations

int main() {
  std::string x = "Hello, world!";
  std::string y = std::move(x);

  std::cout << "Status After: X value moved to y" << '\n';
  if (x.empty()) std::cout << "X status: Empty." << '\n';
  if (!y.empty()) std::cout << "Y Status: NOT Empty" << '\n';
}
