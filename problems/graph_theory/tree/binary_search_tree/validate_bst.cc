// Validate BST

// Write a function that takes in a potentially invalid Binary Search Tree (BST) and returns a
// boolean representing whether the BST is valid.
// Each BST node has an integer value , a left child node, anda right child node. A
// node is said to be a valid BST node if and only if it satisfies the BST property: its value
// is strictly greater than the values of every node to its left; its value is less than or equal
// to the values of every node to its right; and its children nodes are either valid BST nodes
// themselves or None / nutt
// A BST is valid if and only if all of its nodes are valid BST nodes.

#include <cassert>
#include <limits>

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  explicit BST(int val);
  BST& insert(int val);
};

bool validateBstHelper(BST* tree, int min_value, int max_value) {
  if (!tree) return true;  // An empty tree is a valid BST

  if (tree->value < min_value || tree->value >= max_value) return false;

  // Recursively check the left and right subtrees with updated bounds
  return validateBstHelper(tree->left, min_value, tree->value) &&
         validateBstHelper(tree->right, tree->value, max_value);
}

bool validateBst(BST* tree) {
  return validateBstHelper(tree, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
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
  assert(validateBst(root) == true);
}
