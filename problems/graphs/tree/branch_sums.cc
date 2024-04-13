/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Branch Sum
 * @brief:
 * @source:
 * @tags: ["topics/tree", "algorithms/", "methods/"]
 * @status: solved
 */

#include <iostream>
#include <stack>
#include <utility>  // std::pair
#include <vector>

class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  explicit BinaryTree(int value)
      : value(value), left(nullptr), right(nullptr) {}

  BinaryTree* insert(std::vector<int> values, int i = 0) {
    if (i >= values.size()) return nullptr;
    std::vector<BinaryTree*> queue = {this};
    while (queue.size() > 0) {
      BinaryTree* current = queue[0];
      queue.erase(queue.begin());
      if (current->left == nullptr) {
        current->left = new BinaryTree(values[i]);
        break;
      }
      queue.push_back(current->left);
      if (current->right == nullptr) {
        current->right = new BinaryTree(values[i]);
        break;
      }
      queue.push_back(current->right);
    }
    insert(values, i + 1);
    return this;
  }
};

std::vector<int> branch_sums(BinaryTree* root) {
  std::vector<int> branch_sums;

  std::stack<std::pair<BinaryTree*, int>> nodes;
  nodes.push(std::make_pair(root, 0));

  while (!nodes.empty()) {
    std::pair<BinaryTree*, int> current = nodes.top();
    nodes.pop();

    if (current.first->right)
      nodes.push(std::make_pair(current.first->right,
                                current.first->value + current.second));
    if (current.first->left)
      nodes.push(std::make_pair(current.first->left,
                                current.first->value + current.second));

    if (current.first->right == nullptr && current.first->left == nullptr)
      branch_sums.push_back(current.first->value + current.second);
  }

  return branch_sums;
}

int main() {
  BinaryTree* tree = new BinaryTree(1);
  tree->insert({2, 3, 4, 5, 6, 7, 8, 9, 10});

  for (auto& element : branch_sums(tree)) {
    std::cout << element << ' ';
  }
}
