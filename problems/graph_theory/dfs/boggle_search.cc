/*
 * @question: Boggle Search
 * @brief: Generate list of possible words from a character matrix
 * @source:
 * https://www.techiedelight.com/generate-list-of-possible-words-from-a-character-matrix
 * @tags: ["depth_first_search", "dfs", "matrix", "trie" ]
 * @status: unsolved
 */

#include <string>
#include <unordered_set>
#include <vector>

class TriesNode {};

int main() {
  std::vector<std::vector<char>> board = {
      {'M', 'S', 'E'}, {'R', 'A', 'T'}, {'L', 'O', 'N'}};

  std::unordered_set<std::string> words = {"STAR", "NOTE", "SAND", "STONE"};

  std::unordered_set<std::string> output = boggle_search(board, words);
}
