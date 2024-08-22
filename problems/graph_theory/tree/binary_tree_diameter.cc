// Copyright 2024 Adam-Al-Rahman
// Binary Tree Diameter

/**
Write a function that takes in a Binary Tree and returns its diameter. The diameter of a
binary tree is defined as the length of its longest path, even if that path doesn't pass
through the root of the tree.

A path is a collection of connected nodes in a tree, where no node is connected to more
than two other nodes. The length of a path is the number of edges between the path's first
node and its last node.

Each Binary Tree node has an integer value , a left child node, anda right child
node. Children nodes can either be BinaryTree nodes themselves or None / null
*/

#include <cassert>
#include <iostream>

// Current
#include <stack>
#include <unordered_map>

class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  explicit BinaryTree(int value) : value(value) {}
};

int binaryTreeDiameter(BinaryTree* tree) {
  int diameter = 0;
  std::unordered_map<BinaryTree*, int> cache;

  std::stack<BinaryTree*> nodes;
  nodes.push(tree);

  while (!nodes.empty()) {
  }

  return diameter;
}

int main() {
  BinaryTree* root = new BinaryTree(1);
  root->left = new BinaryTree(3);
  root->left->left = new BinaryTree(7);
  root->left->left->left = new BinaryTree(8);
  root->left->left->left->left = new BinaryTree(9);
  root->left->right = new BinaryTree(4);
  root->left->right->right = new BinaryTree(5);
  root->left->right->right->right = new BinaryTree(6);
  root->right = new BinaryTree(2);
  int expected = 6;
  int actual = binaryTreeDiameter(root);

  bool condition = expected == actual;
  assert(condition);

  std::cout << std::boolalpha << condition << std::endl;
}
