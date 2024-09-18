// Copyright 2024 Adam-Al-Rahman
// Simple Suffix Trie Construction

/**
Write a Suffi x Trie class for a Suffix-Trie-like data structure. The class should havea root property set to be
the root node of the trie and should support:

• Creating the trie from a string; this will be done by calling the populateSuffixTrieF rom method upon
class instantiation, which should populate the root of the class.
• Searching for strings in the trie.

Note that every string added to the trie should end with the special endSymbot character: "*"
If you're unfamiliar with Suffix Tries, we recommend watching the Conceptual Overview section of this question's
video explanation before starting to code.
*/

#include <cassert>
#include <string>
#include <unordered_map>

class TrieNode {
 public:
  std::unordered_map<char, TrieNode*> children;
};

class SuffixTrie {
 public:
  TrieNode* root;
  char endSymbol;

  explicit SuffixTrie(std::string str) {
    this->root = new TrieNode();
    this->endSymbol = '*';
    this->populateSuffixTrieFrom(str);
  }

  void insert(const std::string& str) {
    TrieNode* current = root;
    for (char ch : str) {
      if (current->children.find(ch) == current->children.end()) current->children[ch] = new TrieNode();
      current = current->children[ch];
    }

    current->children[this->endSymbol] = nullptr;
  }

  void populateSuffixTrieFrom(std::string str) {
    for (int i = 0; i < str.size(); ++i) insert(str.substr(i));
  }

  bool contains(std::string str) {
    TrieNode* current = root;
    for (char ch : str) {
      if (current->children.find(ch) == current->children.end()) return false;
      current = current->children[ch];
    }

    return current->children.find(this->endSymbol) != current->children.end();
  }
};

int main() {
  std::string word1 = "babc";
  SuffixTrie actual(word1);
  assert(actual.contains("abc") == true);
}
