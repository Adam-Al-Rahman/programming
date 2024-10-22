// Height Balanced Binary Tree

// You're given the root node of a Binary Tree. Write a function that returns true if this
// Binary Tree is height balanced and false if it isn't.

// A Binary Tree is height balanced if for each node in the tree, the difference between the
// height of its left subtree and the height of its right subtree is at most 1 .

// Each BinaryTree node has an integer value , a left child node, anda right child
// node. Children nodes can either be BinaryTree nodes themselves or None / null

#include <algorithm>
#include <cassert>
#include <cstdlib>  // std::abs

class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  explicit BinaryTree(int value) { this->value = value; }
};

struct TreeInfo {
  bool is_balanced;
  int height;
};

TreeInfo getTreeInfo(BinaryTree* node) {
  if (node == nullptr) return TreeInfo{true, -1};

  auto left_subtree_info = getTreeInfo(node->left);
  auto right_subtree_info = getTreeInfo(node->right);

  bool is_balanced = left_subtree_info.is_balanced && right_subtree_info.is_balanced &&
                     std::abs(left_subtree_info.height - right_subtree_info.height) <= 1;

  int height = std::max(left_subtree_info.height, right_subtree_info.height) + 1;

  return TreeInfo{is_balanced, height};
}

bool heightBalancedBinaryTree(BinaryTree* tree) {
  auto tree_info = getTreeInfo(tree);
  return tree_info.is_balanced;
}

int main() {
  auto root = new BinaryTree(1);
  root->left = new BinaryTree(2);
  root->right = new BinaryTree(3);
  root->left->left = new BinaryTree(4);
  root->left->right = new BinaryTree(5);
  root->right->right = new BinaryTree(6);
  root->left->right->left = new BinaryTree(7);
  root->left->right->right = new BinaryTree(8);
  bool expected = true;
  auto actual = heightBalancedBinaryTree(root);
  assert(expected == actual);
}
