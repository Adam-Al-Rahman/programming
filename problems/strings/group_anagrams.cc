// Group Anagrams

// Write a function that takes in an array of strings and groups anagrams together.

// Anagrams are strings made up of exactly the same letters, where order doesn't matter. For
// example, "cinema" and "iceman" are anagrams; similarly, "foo" and "ofo" are
// anagrams.

// Your function should return a list of anagram groups in no particular order.

#include <algorithm>
#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

bool compare(std::vector<std::vector<std::string>> expected, std::vector<std::vector<std::string>> output) {
  if (expected.size() != output.size()) return false;

  for (auto group : expected) {
    std::sort(group.begin(), group.end());
    if (find(output.begin(), output.end(), group) == output.end()) return false;
  }

  return true;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> words) {
  std::unordered_map<std::string, std::vector<std::string>> anagrams;

  for (std::string& word : words) {
    std::string sortedWord = word;
    std::sort(sortedWord.begin(), sortedWord.end());
    anagrams[sortedWord].push_back(word);
  }

  std::vector<std::vector<std::string>> result;
  for (auto [word, list] : anagrams) result.push_back(list);

  return result;
}

int main() {
  std::vector<std::string> words = {"yo", "act", "flop", "tac", "foo", "cat", "oy", "olfp"};
  std::vector<std::vector<std::string>> expected = {{"yo", "oy"}, {"flop", "olfp"}, {"act", "tac", "cat"}, {"foo"}};
  std::vector<std::vector<std::string>> output = groupAnagrams(words);

  for (auto& el : output) sort(el.begin(), el.end());
  assert(compare(expected, output));
}
