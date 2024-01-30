/*
 * @question: Boggle Search
 * @brief: Generate list of possible words from a character matrix
 * @source:
 * https://www.techiedelight.com/generate-list-of-possible-words-from-a-character-matrix
 * @tags: ["depth_first_search", "dfs", "matrix" ]
 * @status: unsolved
 */

#include <string>
#include <unordered_set>
#include <vector>

// possible directions for a single cell
int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};

/* So, from position (x, y), we can move to: */
/* (x – 1, y – 1), (x – 1, y), (x – 1, y + 1), (x, y – 1), (x, y + 1), (x + 1, y
 * – 1) (x + 1, y)(x + 1, y + 1) */

bool is_safe(std::int8_t x, std::int8_t y,
             std::vector<std::vector<bool>> &visited) {
  return ((x >= 0 && x < visited.size()) && (y >= 0 && y < visited[0].size()) &&
          !visited[x][y]);
}

void generator(std::vector<std::vector<char>> const &board,
               std::unordered_set<std::string> &words,
               std::unordered_set<std::string> &result,
               std::vector<std::vector<bool>> &visited, std::int8_t i,
               std::int8_t j, std::string &str_path) {
  // mark as the current visited
  visited[i][j] = true;

  // update the path with the current character and insert it into the set
  str_path += board[i][j];

  // check whether the str_path string is present in the input set(words)
  if (words.find(str_path) != words.end()) {  // true if present in set(words)
    result.insert(str_path);
  }

  // check for all eight possible movements from the current cell
  for (std::int8_t k = 0; k < 8; k++) {
    // skip if a cell is invalid or it is already visited
    if (is_safe(i + row[k], j + col[k], visited)) {
      generator(board, words, result, visited, i + row[k], j + col[k],
                str_path);
    }
  }
}

std::unordered_set<std::string> boggle_search(
    std::vector<std::vector<char>> const &board,
    std::unordered_set<std::string> const &words) {
  std::unordered_set<std::string> result;

  return result;
}

int main() {
  std::vector<std::vector<char>> board = {
      {'M', 'S', 'E'}, {'R', 'A', 'T'}, {'L', 'O', 'N'}};

  std::unordered_set<std::string> words = {"STAR", "NOTE", "SAND", "STONE"};

  std::unordered_set<std::string> output = boggle_search(board, words);
}
