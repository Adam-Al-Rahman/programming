// Copyright 2024 Adam-Al-Rahman

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> splitStringByDelimiter(const std::string& str, char delimiter) {
  std::vector<std::string> result;
  std::istringstream iss(str);
  std::string token;

  while (std::getline(iss, token, delimiter)) {
    result.push_back(token);
  }

  return result;
}

int main() {
  std::string input = "apple, banana,cherry,a";
  char delimiter = ',';
  std::vector<std::string> tokens = splitStringByDelimiter(input, delimiter);

  bool inplace = true;
  for (auto& token : tokens) {
    if (inplace && (token.front() == ' ' || token.back() == ' ')) {
      if (token.front() == ' ') token.erase(0, 1);
      if (token.back() == ' ') token.erase(token.size() - 1, 1);
      if (token.front() == ' ' && token.back() == ' ') {
        token.erase(0, 1);
        token.erase(token.size() - 1, 1);
      }
    }
    std::cout << token << std::endl;
  }

  return 0;
}
