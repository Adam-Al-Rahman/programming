/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Count the special word
 * @brief:
 * You are given a string s. A special word is defined as a substring of length
 * 3 that matches either “quantum” or “ai”. Your task is to write a function
 * that counts the total number of special words in the given string.
 * @source:
 * @tags: ["topics/string", "algorithms/", "methods/sub_string"]
 * @status: unsolved
 */

#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/** Default values of std::uint | std::int
 *
 * All consider the minimum value of the range

The default value of std::uint16_t (which is an unsigned 16-bit integer type) is
zero. In C++, the std::uint16_t type is guaranteed to have a minimum range of 0
to 65535

*/

std::unordered_map<std::string, std::uint16_t> special_words(
    std::string str, std::vector<std::string> sub_strs) {
  // Create a fixed-size map-like container with a maximum of 5 elements
  // std::array<std::pair<std::string, std::uint16_t>, 5> str_count;
  std::unordered_map<std::string, std::uint16_t> str_count;

  for (const std::string& sub_str : sub_strs) {
    std::uint16_t sub_str_len = sub_str.size();
    for (std::size_t i = 0; i + (sub_str_len - 1) < str.size(); i++) {
      std::string sstr = str.substr(i, sub_str_len);

      if (sstr == sub_str) {
        str_count[sub_str] += 1;
        i += (sub_str_len - 1);
      }
    }
  }

  return str_count;
}

int main() {
  //
  std::string str = "quantummeachanicswithaiisawesomeandquantumcomputingtoo";
  std::vector<std::string> sub_strs = {"quantum", "ai"};

  for (const auto& [key, val] : special_words(str, sub_strs)) {
    std::cout << "Key: " << key << " Count: " << val << '\n' << std::flush;
  }
}
