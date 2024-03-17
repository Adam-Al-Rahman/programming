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

bool word_search(std::vector<std::vector<char>> &board, const std::string &word,
                 std::string result = "", std::uint16_t index = 0,
                 std::uint16_t x = 0, std::uint16_t y = 0) {
  if (word[index] != board[x][y]) return false;

  if (word == result) return true;

  bool is_formed = false;

  std::uint16_t n = board.size();
  std::uint16_t m = board[0].size();

  if ((x + 1) >= 0 && (x + 1) < n && board[x + 1][y]) {
    result += board[x][y];
    board[x][y] = 0;
    is_formed |= word_search(board, word, result, index + 1, x + 1, y);
  }

  if ((x - 1 >= 0) && (x - 1) < n && board[x - 1][y]) {
    result += board[x][y];
    board[x][y] = 0;
    is_formed |= word_search(board, word, result, index + 1, x - 1, y);
  }

  if ((y + 1) >= 0 && (y + 1) < m && board[x][y + 1]) {
    result += board[x][y];
    board[x][y] = 0;
    is_formed |= word_search(board, word, result, index + 1, x, y + 1);
  }

  if ((y - 1 >= 0) && (y - 1) < m && board[x][y - 1]) {
    result += board[x][y];
    board[x][y] = 0;
    is_formed |= word_search(board, word, result, index + 1, x, y - 1);
  }

  return is_formed;
}

int main() {
  std::vector<std::vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

  std::string word = "ABCE";

  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      std::cout << board[i][j] << " ";
    }
    std::cout << '\n';
  }

  bool is_possible = word_search(board, word);

  std::cout << "IS POSSIBLE: " << (is_possible ? "YES" : "NO") << std::flush;
}
