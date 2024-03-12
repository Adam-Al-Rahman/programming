/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question:
 * @brief:
 * @source:
 * @tags: ["topics/bits", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <bitset>
#include <cstring>
#include <iostream>

template <typename T>
std::bitset<sizeof(T) * 8> toBits(const T& value) {
  std::bitset<sizeof(T) * 8> bits;
  std::memcpy(bits.data(), &value, sizeof(T));
  return bits;
}

/**
The discrepancy in the output you observed is likely due to the endianness of
the system architecture. In your code, you are using `std::bitset` to represent
the binary representation of an integer, and when you print the bits using the
loop, you iterate through the bits from least significant bit (LSB) to most
significant bit (MSB).

However, the way the bits are printed in the `std::bitset` constructor might be
affected by the endianness of your system. Endianness refers to the byte order
in memory, and it can affect the order in which the bits are stored within a
byte. If your system is little-endian, the bits might be printed in the reverse
order compared to the natural order.

In your case, it seems like the bits are printed in little-endian order when you
use the loop, but the `std::bitset` constructor displays them in big-endian
order. This can create the impression that the bits are "reversed" when you
compare the loop output with the `std::bitset` output.

To ensure consistent output, you may need to manually reverse the bit order when
printing using the loop if your system is little-endian. You can modify your
loop as follows:

```cpp
for (int i = binary_representation.size() - 1; i >= 0; i--) {
  std::cout << binary_representation[i] << std::flush;
}
```

This change should print the bits in the correct order, regardless of the
endianness of your system.
*/
#include <string>

int main() {
  int decimalNumber = 10;          // Example: Convert 10 to binary
  const int sz = sizeof(int) * 8;  // Size of int in bits
  std::bitset<sz> binary_representation = decimalNumber;

  for (std::size_t i = 0; i < binary_representation.size(); i++) {
    std::cout << binary_representation[i] << std::flush;
  }

  std::cout << "\nBinary representation: " << binary_representation
            << std::endl;
}
