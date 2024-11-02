// Split Binary Tree

// Write a function that takes in a Binary Tree with at least one node and checks if that
// Binary Tree can be split into two Binary Trees of equal sum by removing a single
// edge. If this split is possible, return the new sum of each Binary Tree, otherwise
// return O. Note that you do not need to return the edge that was removed.

// The sum of a Binary Tree is the sum of all values in that Binary Tree.

// Each BinaryTree node has an integer value, a left child node,
// and a right child node.Children nodes can either be BinaryTree nodes themselves or None / null

#include <cassert>

class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  explicit BinaryTree(int value) { this->value = value; }
};

struct TreeInfo {
  int current_tree_sum;
  bool can_split;
};

int get_tree_sum(BinaryTree* tree) {
  if (!tree) return 0;

  return tree->value + get_tree_sum(tree->left) + get_tree_sum(tree->right);
}

TreeInfo try_subtrees(BinaryTree* tree, int desired_subtree_sum) {
  if (!tree) return TreeInfo{0, false};

  TreeInfo left_subtree = try_subtrees(tree->left, desired_subtree_sum);
  TreeInfo right_subtree = try_subtrees(tree->right, desired_subtree_sum);

  int current_tree_sum = tree->value + left_subtree.current_tree_sum + right_subtree.current_tree_sum;
  bool can_split = current_tree_sum == desired_subtree_sum || left_subtree.can_split || right_subtree.can_split;

  return TreeInfo{current_tree_sum, can_split};
}

int splitBinaryTree(BinaryTree* tree) {
  int tree_sum = get_tree_sum(tree);

  if (tree_sum % 2 != 0) return 0;

  int desired_subtree_sum = tree_sum / 2;
  bool can_split = try_subtrees(tree, desired_subtree_sum).can_split;

  return can_split ? desired_subtree_sum : 0;
}

int main() {
  BinaryTree* tree = new BinaryTree(2);
  tree->left = new BinaryTree(4);
  tree->left->left = new BinaryTree(4);
  tree->left->right = new BinaryTree(6);
  tree->right = new BinaryTree(10);
  tree->right->left = new BinaryTree(3);
  tree->right->right = new BinaryTree(3);
  int expected = 16;
  auto actual = splitBinaryTree(tree);
  assert(expected == actual);
}
