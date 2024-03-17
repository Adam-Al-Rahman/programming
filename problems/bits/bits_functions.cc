/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question:
 * @brief:
 * @source:
 * @tags: ["topics/bits", "algorithms/", "methods/bits_manipulation"]
 * @status: unsolved
 */

/** bit functions
*
• __builtin_clz(x): the number of zeros at the beginning of the number
• __builtin_ctz(x): the number of zeros at the end of the number
• __builtin_popcount(x): the number of ones in the number
• __builtin_parity(x): the parity (even or odd) of the number of ones
*
*/

/** Bit manipulation
 *
A number of the form 1 << k has a one bit in position k and all other bits are
zero, so we can use such numbers to access single bits of numbers. In
particular, the kth bit of a number is one exactly when x & (1 << k) is not
zero.

```cpp

int x = 234; // 32 bits
for(int i = 31; i >= 0; i--){
  if( x & (1 << i)) std::cout << '1';
  else std::cout << '0';
}

```

It is also possible to modify single bits of numbers using similar ideas. For
example, the formula x | (1 << k) sets the kth bit of x to one, the formula x &
~(1 << k) sets the kth bit of x to zero, and the formula x ^ (1 << k) inverts
the kth bit of x.

The formula x & (x−1) sets the last one bit of x to zero, and the formula x &
−x sets all the one bits to zero, except for the last one bit. The formula x |
(x−1) inverts all the bits after the last one bit. Also note that a positive
number x is a power of two exactly when x & (x−1) = 0
 *
*/

#include <cstdint>
#include <iostream>

int main() {
  std::int32_t x = 5328;  // 00000000000000000001010011010000

  std::cout << __builtin_clz(x) << "\n";       // 19
  std::cout << __builtin_ctz(x) << "\n";       // 4
  std::cout << __builtin_popcount(x) << "\n";  // 5
  std::cout << __builtin_parity(x) << "\n";    // 1
}
