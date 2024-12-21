// Reverse Words in String

// Write a function that takes in a string of words separated by one or more whitespaces and
// returns a string that has these words in reverse order. For example, given the string
// "tim is great" , your function should return "great is tim"

// For this problem, a word can contain special characters, punctuation, and numbers. The words in
// the string will be separated by one or more whitespaces, and the reversed string must contain
// the same whitespaces as the original string. For example, given the string
// "whitespaces    4" you would be expected to return "4    whitespaces"

// Note that you're notallowed to to use any built-in split or reverse methods/functions.
// However, you are allowed to use a built-in join method/function.

// Also note that the input string isn't guaranteed to always contain words.

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

void reverseListRange(std::vector<char>& list, int start, int end) {
  while (start < end) {
    std::swap(list[start], list[end]);

    start += 1;
    end -= 1;
  }
}

// TC: O(n) | SC: O(n)
std::string reverseWordsInString(std::string str) {
  std::vector<char> characters;
  for (auto ch : str) characters.push_back(ch);

  reverseListRange(characters, 0, characters.size() - 1);

  int startOfWord = 0;
  while (startOfWord < characters.size()) {
    int endOfWord = startOfWord;
    while (endOfWord < characters.size() && characters[endOfWord] != ' ') endOfWord += 1;

    reverseListRange(characters, startOfWord, endOfWord - 1);
    startOfWord = endOfWord + 1;
  }

  std::string output;
  for (auto ch : characters) output += ch;

  return output;
}

int main() {
  std::string input = "Everything is incorrect until proven correct";
  std::string expected = "correct proven until incorrect is Everything";
  auto actual = reverseWordsInString(input);
  assert(expected == actual);
}
