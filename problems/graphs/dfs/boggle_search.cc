/*
 * @question: Boggle Search
 * @brief: Generate list of possible words from a character matrix
 * @source:
 * https://www.techiedelight.com/generate-list-of-possible-words-from-a-character-matrix
 * @tags: ["depth_first_search", "dfs", "matrix"]
 * @status: unsolved
 */

#include <memory>
#include <string>
#include <vector>

class Node {
public:
  char letter;
  std::vector<std::shared_ptr<Node>> adjacent_letters;

  Node(char letter) : letter(letter){};

  Node *add_node(char letter) {

    std::shared_ptr<Node> character = std::make_shared<Node>(letter);
    adjacent_letters.push_back(character);

    return this;
  };

  std::vector<std::string> pre_order(std::vector<std::string> &words) {
    return words;
  }
};

int main() {}
