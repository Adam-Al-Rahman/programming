/**
 * Copyright 2024 Adam-Al-Rahman
 */

#include <cstddef>
#include <iostream>

void removeOccurrences(std::string& str, const std::string& substr) {
  std::size_t pos = str.find(substr);
  while (pos != std::string::npos) {
    str.erase(pos, substr.length());
    pos = str.find(substr);
  }
}

int main() {
  std::string text = "asdflksjflkarplksadjflkjdsafkarpskldf";
  std::string pattern = "karp";

  std::cout << "Original text: " << text << std::endl;

  removeOccurrences(text, pattern);

  std::cout << "Text after removing '" << pattern << "': " << text << std::endl;

  return 0;
}
