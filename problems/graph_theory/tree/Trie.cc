// Copyright 2024 Adam-Al-Rahman
// reTRIEval Data Structure
// Using Hashmap, make sure hash collision are very less for optimal results

#include <cstddef>  // std::size_t
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class TrieNode {
 public:
  std::unordered_map<char, std::size_t> children;  // Store indices of child nodes using char keys
  bool is_end_of_word;

  TrieNode() : is_end_of_word(false) {}
};

class Trie {
 public:
  std::vector<TrieNode> nodes;  // Pool of nodes

  Trie() {
    nodes.emplace_back();  // Root node
  }

  void insert(const std::string& word) {
    int node_index = 0;  // Start from the root

    for (char ch : word) {
      if (nodes[node_index].children.find(ch) == nodes[node_index].children.end()) {
        nodes[node_index].children[ch] = nodes.size();
        nodes.emplace_back();
      }
      node_index = nodes[node_index].children[ch];
    }

    nodes[node_index].is_end_of_word = true;
  }

  bool search(const std::string& word) const {
    int node_index = 0;

    for (char ch : word) {
      auto it = nodes[node_index].children.find(ch);
      if (it == nodes[node_index].children.end()) return false;
      node_index = it->second;
    }

    return nodes[node_index].is_end_of_word;
  }

  bool remove(const std::string& word) {
    int node_index = 0;

    std::vector<int> path;  // To track the path of nodes visited
    path.push_back(node_index);

    // Check if the word exists and track the path
    for (char ch : word) {
      auto it = nodes[node_index].children.find(ch);

      // If the word doesn't exist
      if (it == nodes[node_index].children.end()) return false;

      node_index = it->second;
      path.push_back(node_index);
    }

    // The word was not actually present as a complete word
    if (!nodes[node_index].is_end_of_word) return false;

    // Remove the word
    nodes[node_index].is_end_of_word = false;

    // Optional Cleanup: Remove unused nodes
    for (int i = path.size() - 1; i >= 0; --i) {
      int current_index = path[i];
      // Stop if we encounter a node that is end of a word or has children
      if (nodes[current_index].is_end_of_word || !nodes[current_index].children.empty()) break;

      if (i > 0) {  // Avoid removing the root node
        int parent_index = path[i - 1];
        nodes[parent_index].children.erase(nodes[parent_index].children.find(word[i - 1]));
      }
    }

    return true;
  }
};

int main() {
  Trie trie;
  trie.insert("hello");
  trie.insert("hell");
  trie.insert("world");
  trie.remove("hell");

  std::cout << std::boolalpha;
  std::cout << "Search 'hello': " << trie.search("hello") << std::endl;
  std::cout << "Search 'hell': " << trie.search("hell") << std::endl;
  std::cout << "Search 'world': " << trie.search("world") << std::endl;
  std::cout << "Search 'worl': " << trie.search("worl") << std::endl;
  std::cout << "Search 'worlz': " << trie.search("worlz") << std::endl;
  std::cout << "Search 'hello': " << trie.search("hello") << std::endl;
}
