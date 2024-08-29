// Copyright 2024 Adam-Al-Rahman

/**
The complement of an integer is the integer you get when you flip all
the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer x, return its complement.
*/

#include <iostream>

int main() {
  int x = 5;

  // CREATE MASK: for data ( using  data and condition )
  int mask = 0b00000000000000000000000000000001;
  while (mask < x) mask = (mask << 1) | 1;  // why (mask < x), because after flipping the last 1 bit it will be 0

  // MASKING: XOR `x` with `mask` will flip all the bits of num
  std::cout << (x ^ mask) << std::endl;
}
