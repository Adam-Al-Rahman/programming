// Merge Binary Trees

// Write a function that takes in two Binary Trees, merges them, and returns the resulting tree. If
// two nodes overlap during the merge, the value of the merged node should be the sum of the
// overlapping nodes' values.

// Note that your solution can either mutate the input trees or return a new tree.

// Each Binary Tree node has an integer value , a left child node, and a right child node.
// Children nodes can either be Binary Tree nodes themselves or None / null

#include <cassert>

class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  explicit BinaryTree(int value) { this->value = value; }
};

BinaryTree* mergeBinaryTrees(BinaryTree* tree1, BinaryTree* tree2) {
  if (!tree1) return tree2;
  if (!tree2) return tree1;

  tree1->value += tree2->value;

  tree1->left = mergeBinaryTrees(tree1->left, tree2->left);
  tree1->right = mergeBinaryTrees(tree1->right, tree2->right);

  return tree1;
}

int main() {
  BinaryTree* tree1 = new BinaryTree(1);
  tree1->left = new BinaryTree(3);
  tree1->left->left = new BinaryTree(7);
  tree1->left->right = new BinaryTree(4);
  tree1->right = new BinaryTree(2);

  BinaryTree* tree2 = new BinaryTree(1);
  tree2->left = new BinaryTree(5);
  tree2->left->left = new BinaryTree(2);
  tree2->right = new BinaryTree(9);
  tree2->right->left = new BinaryTree(7);
  tree2->right->right = new BinaryTree(6);

  auto actual = mergeBinaryTrees(tree1, tree2);
  assert(actual->value == 2);
  assert(actual->left->value == 8);
  assert(actual->left->left->value == 9);
  assert(actual->left->right->value == 4);
  assert(actual->right->value == 11);
  assert(actual->right->left->value == 7);
  assert(actual->right->right->value == 6);
}
