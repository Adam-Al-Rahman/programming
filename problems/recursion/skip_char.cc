/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Skip characters
 * @brief: From a given string skip a character
 * @source:
 * @tags: ["topics/recursion", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <iostream>
#include <memory>
#include <string>

std::string skip_char(std::shared_ptr<std::string> str) {
  if (str->empty()) return "";

  if (str->at(0) == 'a') {
    return "" + skip_char(
                    std::make_shared<std::string>(str->substr(1, str->size())));
  } else {
    return str->at(0) + skip_char(std::make_shared<std::string>(
                            str->substr(1, str->size())));
  }

  return skip_char(str);
}

int main() {
  std::cout << skip_char(std::make_shared<std::string>("characters"));
}
