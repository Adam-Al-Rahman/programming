/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Lambda
 * Functions
 * @brief:
 * @source:
 * @tags: ["topics/", "algorithms/",
 * "methods/"]
 * @status: unsolved
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

int main() {
  std::function<std::string(std::string &)> rev_string =
      [](std::string &str) -> std::string {
    std::reverse(str.begin(), str.end());  // inplace reverse
    return str;
  };

  std::string input = "Hello, world!";
  std::string reversed = rev_string(input);  // inplace reverse

  std::cout << "Original: " << input << std::endl;  // it will be reverse too
  std::cout << "Reversed: " << reversed << std::endl;
}
