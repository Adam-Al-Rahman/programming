// Symmetrical Tree

// Write a function that takes in a Binary Tree and returns if that tree is symmetrical. A tree is
// symmetrical if the left and right subtrees are mirror images of each other.

// Each Binary Tree node has an integer value , a left child node, and a right child node.
// Children nodes can either be BinaryTree nodes themselves or None / null

#include <cassert>

class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  explicit BinaryTree(int value) { this->value = value; }
};

bool symmetricalTree(BinaryTree* tree, BinaryTree* node = nullptr) {
  if (!node) node = tree;

  if (!tree && !node) return true;
  if (!tree || !node) return false;

  return ((tree->value == node->value) && symmetricalTree(tree->left, node->right) &&
          symmetricalTree(tree->right, node->left));
}

int main() {
  BinaryTree* tree = new BinaryTree(10);
  tree->left = new BinaryTree(5);
  tree->right = new BinaryTree(5);
  tree->left->left = new BinaryTree(7);
  tree->left->right = new BinaryTree(9);
  tree->right->left = new BinaryTree(9);
  tree->right->right = new BinaryTree(7);
  auto expected = true;
  auto actual = symmetricalTree(tree);
  assert(expected == actual);
}
