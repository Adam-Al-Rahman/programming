// Copyright 2024 Adam-Al-Rahman
// Boggle Board
// Topic: graph, trie, dfs, backtracking
// Status: Unsolved

/**
w = number of words in vector
s = max size of characters in a vector strings

Space: ws + nm
Time: ws + nm * 8^{s}
*/

/**

You're given a two-dimensional array (a matrix) of potentially unequal height and width
containing letters; this matrix represents a boggle board. You're also given a list of words.
Write a function that returns an array of all the words contained in the boggle board. The final
words don't need to be in any particular order.

Write a function that returns an array of all the words contained in the boggle board. The final
words don't need to be in any particular order.

A word is constructed in the boggle board by connecting adjacent (horizontally, vertically, or
diagonally) letters, without using any single letter at a given position more than once; while a
word can of course have repeated letters, those repeated letters must come from different
positions in the boggle board in order for the word to be contained in the board. Note that two
or more words are allowed to overlap and use the same letters in the boggle board.
*/

#include <cassert>
#include <cstddef>  // std::size_t
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace px {
using node = std::tuple<int, int>;
}

bool contains(std::vector<std::string> wordArray, std::string targetWord) {
  for (std::string word : wordArray) {
    if (targetWord == word) return true;
  }
  return false;
}

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
    nodes.emplace_back();  // Root node, with default value of `TrieNode` contructor
  }

  void insert(const std::string& word) {
    int node_index = 0;  // Start from the root

    for (char ch : word) {
      if (nodes[node_index].children.find(ch) == nodes[node_index].children.end()) {
        nodes[node_index].children[ch] = nodes.size();
        nodes.emplace_back();  // Add a new default-constructed node
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

std::vector<px::node> get_neighbors(int i, int j, const std::vector<std::vector<char>>& board) {
  std::vector<px::node> neighbors;
  // Directions for moving in the matrix: up, down, left, right, diags
  std::vector<px::node> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

  int rows = board.size();
  int cols = board[0].size();

  for (const auto& [dx, dy] : directions) {
    int new_i = i + dx;
    int new_j = j + dy;

    if (new_i >= 0 && new_i < rows && new_j >= 0 && new_j < cols) neighbors.push_back(std::make_tuple(new_i, new_j));
  }

  return neighbors;
}

void explore(int i, int j, const std::vector<std::vector<char>>& board, const std::vector<TrieNode>& trie_nodes,
             std::vector<std::vector<bool>> visited, std::unordered_set<std::string> exist_words) {
  if (visited[i][j]) return;

  char letter = board[i][j];
  if () }

std::vector<std::string> boggleBoard(std::vector<std::vector<char>> board, std::vector<std::string> words) {
  std::unordered_set<std::string> exist_words;

  // potentially unequal height and width
  std::vector<std::vector<bool>> visited(board.size());
  for (std::size_t i = 0; i < board.size(); ++i) visited[i].resize(board[i].size(), false);

  // Create Trie
  Trie trie;
  for (auto word : words) trie.insert(word);

  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[i].size(); ++j) explore(i, j, board, trie.nodes, visited, exist_words);
  }

  return std::vector(exist_words.begin(), exist_words.end());
}

int main() {
  std::vector<std::vector<char>> board = {
      {'t', 'h', 'i', 's', 'i', 's', 'a'}, {'s', 'i', 'm', 'p', 'l', 'e', 'x'}, {'b', 'x', 'x', 'x', 'x', 'e', 'b'},
      {'x', 'o', 'g', 'g', 'l', 'x', 'o'}, {'x', 'x', 'x', 'D', 'T', 'r', 'a'}, {'R', 'E', 'P', 'E', 'A', 'd', 'x'},
      {'x', 'x', 'x', 'x', 'x', 'x', 'x'}, {'N', 'O', 'T', 'R', 'E', '-', 'P'}, {'x', 'x', 'D', 'E', 'T', 'A', 'E'},
  };
  std::vector<std::string> words = {"this",   "is",    "not",  "a",        "simple",
                                    "boggle", "board", "test", "REPEATED", "NOTRE-PEATED"};
  std::vector<std::string> expected = {"this", "is", "a", "simple", "boggle", "board", "NOTRE-PEATED"};
  std::vector<std::string> actual = boggleBoard(board, words);
  assert(actual.size() == expected.size());
  for (std::string word : actual) {
    assert(contains(expected, word));
  }
}
