/*
 * @question: First Uppercase Letter
 * @brief: Given a string find the first uppercase letter
 * @source:
 * https://www.geeksforgeeks.org/first-uppercase-letter-in-a-string-iterative-and-recursive/
 * @tags: ["recursion", "characters", "vector"]
 * @status: unsolved
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

/**
In C++, `int` and `wint_t` are different types with distinct purposes:

1. **`int`:**
   - `int` is a fundamental data type in C++ representing signed integers.
   - Its size is platform-dependent, typically 32 bits on most modern systems.
   - It is commonly used for integer arithmetic and storage of whole numbers.

2. **`wint_t`:**
   - `wint_t` is a type specifically designed for representing wide characters
in C and C++.
   - It is an integer type capable of representing any valid wide character,
including special values like `WEOF`.
   - Its size is implementation-dependent but is often chosen to be large enough
to represent any valid wide character.
   - `wint_t` is commonly used in functions from the `<cwchar>` header that deal
with wide character input and output.

When working with wide characters, you often use `wint_t` in functions like
those from the `<cwchar>` header, such as `fgetwc`, `fputwc`, `getwc`, `putwc`,
etc. These functions take or return wide characters and often use `wint_t` to
represent the wide character type.
*/

#include <cctype>
#include <iostream>
#include <string>

char first_uppercase_letter(std::string word, int index = 0) {
  if (index >= word.size()) return '\0';
  int character_unicode = static_cast<int>(word[index]);

  /* if (character_unicode >= 65 && character_unicode <= 91) return word[index];
   */

  if (std::isupper(static_cast<unsigned char>(word[index]))) return word[index];

  return first_uppercase_letter(word, index + 1);
}

int main() {
  std::cout << "First Uppercase letter: "
            << first_uppercase_letter("quantumMechanics") << std::flush;
}
