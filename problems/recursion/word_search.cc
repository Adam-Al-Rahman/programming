/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Word Search
 * @brief:
 * @source: https://leetcode.com/problems/word-search/
 * @tags: ["topics/recursion", "algorithms/backtracking", "methods/"]
 * @status: unsolved
 */

#include <iostream>
#include <string>
#include <vector>

bool word_search(std::vector<std::vector<char>> &board, std::string word) {}

int main() {
  std::vector<std::vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

  std::string word = "ABCB";

  bool is_possible = word_search(board, word);

  std::cout << "IS POSSIBLE" << (is_possible ? "YES" : "NO") << std::flush;
}
