/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: In order tree traversal
 * @brief: Implement Morris In order algorithm
 * @source:
 * @tags: ["topics/tree", "algorithms/morris", "methods/traversal"]
 * @status: unsolved
 */

#include <cstdint>
#include <iostream>
#include <vector>

typedef class Node {
 public:
  std::uint16_t value;
  Node* left = nullptr;
  Node* right = nullptr;

  Node(std::uint16_t value) : value(value) {}
} node_t;

std::vector<std::uint16_t> morris_inorder(node_t* root) {
  std::vector<std::uint16_t> inorder;

  node_t* current = root;
  while (current != nullptr) {
    if (current->left == nullptr) {
      inorder.push_back(current->value);
      current = current->right;
    } else {
      // Find the inorder predecessor of current
      node_t* predecessor = current->left;
      // predecessor->right != current: check whether right pointer to next
      // element to be the current
      while (predecessor->right != nullptr && predecessor->right != current) {
        predecessor = predecessor->right;
      }

      if (predecessor->right == nullptr) {
        predecessor->right = current;  // Make current as the right child of its
                                       // inorder predecessor
        current = current->left;       // Move to the left subtree
      } else {
        // Revert the changes made in the if block above
        predecessor->right = nullptr;
        inorder.push_back(current->value);  // Process the node
        current = current->right;           // Move to the right subtree
      }
    }
  }

  return inorder;
}

int main() {
  node_t* root = new node_t(1);
  root->left = new node_t(2);
  root->right = new node_t(3);
  root->left->left = new node_t(4);
  root->left->right = new node_t(5);

  for (std::uint16_t& element : morris_inorder(root)) {
    std::cout << element << ' ';
  }
  std::cout << std::flush;
}
