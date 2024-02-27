/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Subsequence
 * @brief: find subsequences in a string
 * @source:
 * @tags: ["topics/recursion", "algorithms/", "methods/search"]
 * @status: unsolved
 */

#include <iostream>
#include <memory>
#include <string>
#include <vector>

std::vector<std::string> subseq(std::shared_ptr<std::string> str,
                                std::string result = "") {
  if (str->empty()) {
    return !result.empty() ? std::vector<std::string>{result}
                           : std::vector<std::string>{};
  }

  std::vector<std::string> left =
      subseq(std::make_shared<std::string>(str->substr(1, str->size())),
             result + str->at(0));
  std::vector<std::string> right = subseq(
      std::make_shared<std::string>(str->substr(1, str->size())), result);

  left.insert(
      left.end(), right.begin(),
      right.end());  // insert(position iterator, first element, last element);

  return left;
}

int main() {
  for (std::string element : subseq(std::make_shared<std::string>("abc"))) {
    std::cout << element << ' ';
  }
}
