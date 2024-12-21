// Minimum characters for words

// Write a function that takes in an array of words and returns the smallest array of characters
// needed to form all of the words. The characters don't need to be in any particular order.

// For example, the characters ["y", "o", u", "r"] re needed to form the words
// ["your", "you","or", "yo"]

// Note: the input words won't contain any spaces; however, they might contain punctuation
// and/or special characters.

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

std::unordered_map<char, int> countCharFreq(const std::string& string) {
  std::unordered_map<char, int> charFreq;

  for (auto ch : string) {
    if (charFreq.find(ch) == charFreq.end()) charFreq[ch] = 0;

    charFreq[ch] += 1;
  }

  return charFreq;
}

void updateMaxFreq(const std::unordered_map<char, int>& freqs, std::unordered_map<char, int>& maxFreq) {
  for (const auto& [ch, freq] : freqs) {
    maxFreq[ch] = std::max(freq, maxFreq[ch]);
  }
}

std::vector<char> toArray(const std::unordered_map<char, int>& charFreq) {
  std::vector<char> characters;

  for (const auto& [ch, freq] : charFreq) {
    for (int i = 0; i < freq; i++) characters.push_back(ch);
  }

  return characters;
}

std::vector<char> minimumCharactersForWords(std::vector<std::string> words) {
  std::unordered_map<char, int> maxCharFreq;

  for (auto const& word : words) {
    auto charFreq = countCharFreq(word);
    updateMaxFreq(charFreq, maxCharFreq);
  }

  return toArray(maxCharFreq);
}

int main() {
  std::vector<std::string> input = {"this", "that", "did", "deed", "them!", "a"};
  std::vector<char> expected = {'t', 't', 'h', 'i', 's', 'a', 'd', 'd', 'e', 'e', 'm', '!'};

  auto actual = minimumCharactersForWords(input);
  std::sort(actual.begin(), actual.end());
  std::sort(expected.begin(), expected.end());

  assert(expected == actual);
}
