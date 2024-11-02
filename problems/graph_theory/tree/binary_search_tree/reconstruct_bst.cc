// Reconstruct BST

// The pre-order traversal of a Binary Tree is a traversal technique that starts at the tree's root
// node and visits nodes in the following order:
// 1. Current node
// 2. Left subtree
// 3. Right subtree

// Given a non-empty array of integers representing the pre-order traversal of a Binary Search
// Tree (BST), write a function that creates the relevant BST and returns its root node.
//
// The input array will contain the values of BST nodes in the order in which these nodes would
// be visited with a pre-order traversal.

// Each BST node has an integer value , a left child node, anda right child node. A
// node is said to be a valid BST node if and only if it satisfies the BST property: its value is
// strictly greater than the values of every node to its left; its value is less than or equal to
// the values of every node to its right; and its children nodes are either valid BST nodes
// themselves or None / null

#include <cassert>
#include <limits>
#include <vector>

class BST {
 public:
  int value;
  BST* left = nullptr;
  BST* right = nullptr;

  explicit BST(int value) { this->value = value; }
};

std::vector<int> getDfsOrder(BST* node, std::vector<int>& values) {
  values.push_back(node->value);

  if (node->left != nullptr) getDfsOrder(node->left, values);
  if (node->right != nullptr) getDfsOrder(node->right, values);

  return values;
}

// TC: O(n^2) | SC: O(n)
BST* reconstruct_bst_helper(const std::vector<int>& values, int start_idx, int end_idx) {
  if (start_idx > end_idx) return nullptr;

  int right_idx = end_idx + 1;
  for (int i = start_idx + 1; i <= end_idx; ++i) {
    if (values[i] >= values[start_idx]) {
      right_idx = i;
      break;
    }
  }

  auto left_subtree = reconstruct_bst_helper(values, start_idx + 1, right_idx - 1);
  auto right_subtree = reconstruct_bst_helper(values, right_idx, end_idx);

  BST* node = new BST(values[start_idx]);
  node->left = left_subtree;
  node->right = right_subtree;

  return node;
}

// Optimal Algorithm TC: O(n) | SC: O(n)
struct TreeInfo {
  int rootIdx;
};

BST* reconstructBstFromRange(int lowerBound, int upperBound, std::vector<int>& preOrderTraversalValues,
                             TreeInfo& currentSubtreeInfo) {
  if (currentSubtreeInfo.rootIdx == preOrderTraversalValues.size()) return nullptr;

  int rootValue = preOrderTraversalValues[currentSubtreeInfo.rootIdx];
  if (rootValue < lowerBound || rootValue >= upperBound) return nullptr;

  currentSubtreeInfo.rootIdx += 1;
  auto leftSubtree = reconstructBstFromRange(lowerBound, rootValue, preOrderTraversalValues, currentSubtreeInfo);
  auto rightSubtree = reconstructBstFromRange(rootValue, upperBound, preOrderTraversalValues, currentSubtreeInfo);

  auto tree = new BST(rootValue);
  tree->left = leftSubtree;
  tree->right = rightSubtree;
  return tree;
}

BST* reconstructBst(std::vector<int> preOrderTraversalValues) {
  // return reconstruct_bst_helper(preOrderTraversalValues, 0, preOrderTraversalValues.size() - 1);
  auto treeInfo = TreeInfo{0};
  return reconstructBstFromRange(std::numeric_limits<int>::min(), std::numeric_limits<int>::max(),
                                 preOrderTraversalValues, treeInfo);
}

int main() {
  std::vector<int> preOrderTraversalValues = {10, 4, 2, 1, 3, 17, 19, 18};

  auto tree = new BST(10);
  tree->left = new BST(4);
  tree->left->left = new BST(2);
  tree->left->left->left = new BST(1);
  tree->left->right = new BST(3);
  tree->right = new BST(17);
  tree->right->right = new BST(19);
  tree->right->right->left = new BST(18);

  std::vector<int> v1;
  auto expected = getDfsOrder(tree, v1);

  auto actual = reconstructBst(preOrderTraversalValues);

  std::vector<int> v2;
  auto actualDfsOrder = getDfsOrder(actual, v2);

  assert(expected == actualDfsOrder);
}
