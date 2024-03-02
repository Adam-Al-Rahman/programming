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
    std::unordered_map<char, std::string> &keypad, std::string phone_number,
    std::string result = "") {
  std::vector<std::string> permutations;

  if (phone_number.empty()) {
    permutations.push_back(result);
    return permutations;
  }

  char first_digit = phone_number[0];
  std::string remaining_digits = phone_number.substr(1);

  for (char c : keypad[first_digit]) {
    std::vector<std::string> sub_per =
        phone_number_mnemonics(keypad, remaining_digits, result + c);
    permutations.insert(permutations.end(), sub_per.begin(), sub_per.end());
  }

  return permutations;
}

int main() {
  std::string phone_number = "234";
  std::unordered_map<char, std::string> keypad = {
      {'0', "0"},   {'1', "1"},   {'2', "abc"},  {'3', "def"}, {'4', "ghi"},
      {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

  for (std::string mnemonics : phone_number_mnemonics(keypad, phone_number)) {
    std::cout << mnemonics << ' ';
  }
}
