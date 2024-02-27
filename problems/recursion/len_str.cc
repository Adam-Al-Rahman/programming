/*
 * @question: Length of string
 * @brief: find the length of string using recursion
 * @source:
 * https://www.geeksforgeeks.org/program-for-length-of-a-string-using-recursion/
 * @tags: ["recursion", "string"]
 * @status: unsolved
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

#include <iostream>
#include <string>

std::uint16_t len_str(const std::string &str, std::uint16_t str_len = 0) {
  if (str[str_len] == '\0') return str_len;
  return len_str(str, str_len + 1);
}

int main() { std::cout << "String Len: " << len_str("Hello world"); }
