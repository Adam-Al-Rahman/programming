// Evaluate Expression Tree

// You're given a binary expression tree. Write a function to evaluate this tree mathematically and return a single
// resulting integer.

/*
All leaf nodes in the tree represent operands, which will always be positive
integers. All of the other nodes represent operators. There are 4 operators
supported, each of which is represented by a negative integer:
• -1 : Addition operator, adding the left and right subtrees.
• -2 : Subtraction operator, subtracting the right subtree from the left subtree.
• -3 : Division operator, dividing the left subtree by the right subtree. If the result is a decimal, it should be
rounded towards zero.
• -4 : Multiplication operator, multiplying the left and right subtrees.
*/

// You can assume the tree will always be a valid expression tree. Each operator also
// works as a grouping symbol, meaning the bottom of the tree is always evaluated
// first, regardless of the operator.

#include <cassert>

class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  explicit BinaryTree(int value) { this->value = value; }
};

int evaluateExpressionTree(BinaryTree* tree) {
  if (!tree->left && !tree->right) return tree->value;

  int lt_value = evaluateExpressionTree(tree->left);
  int rt_value = evaluateExpressionTree(tree->right);

  if (tree->value == -1) return lt_value + rt_value;
  if (tree->value == -2) return lt_value - rt_value;
  if (tree->value == -3) return lt_value / rt_value;
  if (tree->value == -4) return lt_value * rt_value;
  return 0;
}

int main() {
  BinaryTree* tree = new BinaryTree(-1);
  tree->left = new BinaryTree(2);
  tree->right = new BinaryTree(-2);
  tree->right->left = new BinaryTree(5);
  tree->right->right = new BinaryTree(1);
  int expected = 6;
  auto actual = evaluateExpressionTree(tree);
  assert(expected == actual);
}
