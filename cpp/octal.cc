/**
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

/**
In C++, when a numeric literal starts with a '0' (zero) and is followed by
digits, the compiler interprets it as an octal (base-8) constant. Therefore, in
the expression `int a = 032;`, the value assigned to the variable `a` is the
octal representation of the decimal number 26.

Here's the breakdown:

- The '0' prefix indicates that the number is in octal notation.
- The digits '3' and '2' in octal represent the decimal value (3 * 8^1) + (2 *
8^0) = 24 + 2 = 26.

So, `int a = 032;` is equivalent to `int a = 26;` in decimal notation.

It's important to note that starting with C++14, you can also use the '0b'
prefix for binary literals and the '0x' prefix for hexadecimal literals.
*/

#include <iostream>

int main() {
  int a = 032;                        // 0: means octal
  int b = 0000000000000000000000032;  // no matter any number of zero it's still
                                      // will be octal
  std::cout << "a: " << a << "\n";
  std::cout << "b: " << b << "\n";
}
