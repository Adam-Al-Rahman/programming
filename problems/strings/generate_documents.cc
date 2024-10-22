// Generate Document

// You're given a string of available characters and a string representing a document that you need
// to generate. Write a function that determines if you can generate the document using the
// available characters. If you can generate the document, your function should return true ;
// otherwise, it should return false

// You're only able to generate the document if the frequency of unique characters in the
// characters string is greater than or equal to the frequency of unique characters in the document
// string. For example, if you're given characters = "abcabc" and document = "aabbccc"
// you cannot generate the document because you're missing one c .

// The document that you need to create may contain any characters, including special characters,
// capital letters, numbers, and spaces.
// Note: you can always generate the empty string ("")

#include <cassert>
#include <string>
#include <unordered_map>

bool generateDocument(std::string characters, std::string document) {
  std::unordered_map<char, int> char_count;
  for (char& ch : characters) {
    if (char_count.find(ch) == char_count.end()) char_count[ch] = 0;
    char_count[ch] += 1;
  }

  for (char& ch : document) {
    if (char_count.find(ch) == char_count.end() || char_count[ch] == 0) return false;
    char_count[ch] -= 1;
  }

  return true;
}

int main() {
  auto characters = "aheaollabbhb";
  auto document = "hello";
  auto expected = true;
  auto actual = generateDocument(characters, document);
  assert(expected == actual);
}
