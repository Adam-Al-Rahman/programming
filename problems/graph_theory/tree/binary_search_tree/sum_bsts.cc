// Sum BSTs

// You're given a Binary Tree. As with any Binary Tree, this tree may contain one or more Binary
// Search Trees (BSTs), and it may even be a BST itself.

// Write a function that returns the sum of all the values of nodes in this tree which are part of a
// BST containing at least 3 nodes.

// Each Binary Tree node has an integer value , a left child node, anda right child node.
// Children nodes can either be BinaryTree nodes themselves or None / null

// A BST is a special type of Binary Tree whose nodes all satisfy the BST property. A node satisfies
// the BST property if its value is strictly greater than the values of every node to its left; its
// value is less than or equal to the values of every node to its right; and its children nodes are
// either valid BST nodes themselves or None / null

#include <algorithm>
#include <cassert>
#include <climits>

class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

struct TreeInfo {
  bool isBst;
  int maxValue;
  int minValue;
  int bstSum;
  int bstSize;
  int totalSumBstNodes;

  TreeInfo(bool isBst, int maxValue, int minValue, int bstSum, int bstSize, int totalSumBstNodes)
      : isBst(isBst),
        maxValue(maxValue),
        minValue(minValue),
        bstSum(bstSum),
        bstSize(bstSize),
        totalSumBstNodes(totalSumBstNodes) {}
};

TreeInfo getTreeInfo(BinaryTree* tree) {
  if (tree == nullptr) return TreeInfo(true, INT_MIN, INT_MAX, 0, 0, 0);

  TreeInfo leftTreeInfo = getTreeInfo(tree->left);
  TreeInfo rightTreeInfo = getTreeInfo(tree->right);

  bool satisfiesBstProp = tree->value > leftTreeInfo.maxValue && tree->value <= rightTreeInfo.minValue;
  bool isBst = satisfiesBstProp && leftTreeInfo.isBst && rightTreeInfo.isBst;

  int maxValue = std::max(tree->value, std::max(leftTreeInfo.maxValue, rightTreeInfo.maxValue));
  int minValue = std::min(tree->value, std::min(leftTreeInfo.minValue, rightTreeInfo.minValue));

  int bstSum = 0;
  int bstSize = 0;

  int totalSumBstNodes = leftTreeInfo.totalSumBstNodes + rightTreeInfo.totalSumBstNodes;

  if (isBst) {
    bstSum = tree->value + leftTreeInfo.bstSum + rightTreeInfo.bstSum;
    bstSize = 1 + leftTreeInfo.bstSize + rightTreeInfo.bstSize;

    if (bstSize >= 3) totalSumBstNodes = bstSum;
  }

  return TreeInfo(isBst, maxValue, minValue, bstSum, bstSize, totalSumBstNodes);
}

int sumBsts(BinaryTree* tree) { return getTreeInfo(tree).totalSumBstNodes; }

int main() {
  BinaryTree* root = new BinaryTree(8);
  root->left = new BinaryTree(2);
  root->left->left = new BinaryTree(1);
  root->left->right = new BinaryTree(10);
  root->right = new BinaryTree(9);
  root->right->right = new BinaryTree(5);
  auto expected = 13;
  auto actual = sumBsts(root);
  assert(expected == actual);
}
