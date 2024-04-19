/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Find closest value in BST
 * @brief:
 * @source:
 * @tags: ["topics/bst", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <iostream>
#include <queue>

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  explicit BST(int val) : value(val), left(nullptr), right(nullptr) {}
  BST& insert(int val);
};

int findClosestValueInBst(BST* tree, int target) {
  std::queue<BST*> nodes;
  nodes.push(tree);

  int closest_value = 0;
  while (!nodes.empty()) {
    BST* current = nodes.front();
    nodes.pop();
  }

  return closest_value;
}

int main() {
  BST* root = new BST(10);
  root->left = new BST(5);
  root->left->left = new BST(2);
  root->left->left->left = new BST(1);
  root->left->right = new BST(5);
  root->right = new BST(15);
  root->right->left = new BST(13);
  root->right->left->right = new BST(14);
  root->right->right = new BST(22);
  int expected = 13;
  int actual = findClosestValueInBst(root, 12);
  std::cout << (expected == actual);
}
