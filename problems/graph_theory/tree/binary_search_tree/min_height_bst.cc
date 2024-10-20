// Min height BST

// Write a function that takes in a non-empty sorted array of distinct integers, constructs a BST
// from the integers, and returns the root of the BST.
// The function should minimize the height of the BST.
// You've been provided with a BST class that you'll have to use to construct the BST.

#include <algorithm>
#include <cassert>
#include <climits>
#include <vector>

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  explicit BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

bool validateBstHelper(BST* tree, int minValue, int maxValue) {
  if (tree->value < minValue || tree->value >= maxValue) {
    return false;
  }
  if (tree->left != nullptr && !validateBstHelper(tree->left, minValue, tree->value)) {
    return false;
  }
  if (tree->right != nullptr && !validateBstHelper(tree->right, tree->value, maxValue)) {
    return false;
  }
  return true;
}

std::vector<int> inOrderTraverse(BST* tree, std::vector<int> array) {
  if (tree->left != nullptr) {
    array = inOrderTraverse(tree->left, array);
  }
  array.push_back(tree->value);
  if (tree->right != nullptr) {
    array = inOrderTraverse(tree->right, array);
  }
  return array;
}

bool validateBst(BST* tree) { return validateBstHelper(tree, INT_MIN, INT_MAX); }

template <class BST>
int getTreeHeight(BST* tree, int height) {
  if (tree == nullptr) return height;
  int leftTreeHeight = getTreeHeight(tree->left, height + 1);
  int rightTreeHeight = getTreeHeight(tree->right, height + 1);
  return std::max(leftTreeHeight, rightTreeHeight);
}

// TC: O(nlog(n)) | SC: O(n)
BST* construct_min_height_bst(const std::vector<int>& array, BST* tree, int start_idx, int end_idx) {
  if (end_idx < start_idx) return nullptr;

  int mid_idx = (start_idx + end_idx) / 2;
  int value = array[mid_idx];

  if (tree == nullptr)
    tree = new BST(value);
  else
    tree->insert(value);

  construct_min_height_bst(array, tree, start_idx, mid_idx - 1);
  construct_min_height_bst(array, tree, mid_idx + 1, end_idx);

  return tree;
}

// TC: O(n) | SC: O(n)
BST* construct_min_height_bst_manual_insert(const std::vector<int>& array, int start_idx, int end_idx) {
  if (end_idx < start_idx) return nullptr;

  int mid_idx = (start_idx + end_idx) / 2;

  BST* tree = new BST(array[mid_idx]);
  tree->left = construct_min_height_bst_manual_insert(array, start_idx, mid_idx - 1);
  tree->right = construct_min_height_bst_manual_insert(array, mid_idx + 1, end_idx);

  return tree;
}

BST* minHeightBst(std::vector<int> array) { return construct_min_height_bst_manual_insert(array, 0, array.size() - 1); }

int main() {
  std::vector<int> array{1, 2, 5, 7, 10, 13, 14, 15, 22};
  auto tree = minHeightBst(array);

  assert(validateBst(tree));
  assert(getTreeHeight(tree, 0) == 4);

  auto inOrder = inOrderTraverse(tree, {});
  std::vector<int> expected{1, 2, 5, 7, 10, 13, 14, 15, 22};
  assert(inOrder == expected);
}
