/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Phone number Mnemonics
 * @brief: according to the phone dial for each number it is represented by 3
 * letters. Find all possible mnemonics from each number
 * - Valid mnemonics: may only contain letters and the digits 0 and 1;
 * @source:
 * @tags: ["topics/", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::string> phone_number_mnemonics(
    std::unordered_map<char, std::string> keypad, std::string phone_number,
    std::string result = "") {
  if (phone_number.empty()) return {result};

  std::vector<std::string> permutations;

  for (std::size_t i = 0; i < keypad[phone_number[0]].size(); i++) {
    result += keypad[phone_number[0]][i];
    phone_number.erase(phone_number.begin());

    std::vector<std::string> current_perm =
        phone_number_mnemonics(keypad, phone_number, result);

    result.pop_back();
    permutations.insert(permutations.end(), current_perm.begin(),
                        current_perm.end());
  }

  return permutations;
}

int main() {
  std::string phone_number = "1905";
  std::unordered_map<char, std::string> keypad = {
      {'0', "0"},   {'1', "1"},   {'2', "abc"},  {'3', "def"}, {'4', "ghi"},
      {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "xyz"}};

  for (std::string mnemonics : phone_number_mnemonics(keypad, phone_number)) {
    std::cout << mnemonics << ' ';
  }
}
