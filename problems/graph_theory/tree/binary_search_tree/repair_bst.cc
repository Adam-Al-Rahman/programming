// Repair BST

// You're given a Binary Search Tree (BST) that has at least 2 nodes and that only has nodes with
// unique values (no duplicate values). Exactly two nodes in the BST have had their values swapped,
// therefore breaking the BST. Write a function that returns a repaired version of the tree with all
// values on the correct nodes.

// Your function can mutate the original tree; you do not need to create a new one. Moreover, the
// shape of the returned tree should be exactly the same as that of the original input tree.

// Each BST node has an integer value , a left child node, anda right child node. Anode is
// said to be a valid BST node if and only if it satisfies the BST property: its value is strictly
// greater than the values of every node to its left; its value is less than or equal to the values of
// every node to its right; and its children nodes are either valid BST nodes themselves or None null

#include <algorithm>
#include <cassert>
#include <stack>
#include <vector>

class BST {
 public:
  int value;
  BST* left = nullptr;
  BST* right = nullptr;

  BST(int value) { this->value = value; }
};

BST* repairBst(BST* tree) {
  BST* nodeOne = nullptr;
  BST* nodeTwo = nullptr;
  BST* previousNode = nullptr;

  std::stack<BST*> st;
  BST* currentNode = tree;

  while (currentNode != nullptr || !st.empty()) {
    while (currentNode != nullptr) {
      st.push(currentNode);
      currentNode = currentNode->left;
    }

    currentNode = st.top();
    st.pop();

    if (previousNode != nullptr && previousNode->value > currentNode->value) {
      if (nodeOne == nullptr) nodeOne = previousNode;
      nodeTwo = currentNode;
    }

    previousNode = currentNode;
    currentNode = currentNode->right;
  }

  std::swap(nodeOne->value, nodeTwo->value);
  return tree;
}

void inOrderTraverse(BST* tree, std::vector<int>& array) {
  if (tree->left != nullptr) {
    inOrderTraverse(tree->left, array);
  }
  array.push_back(tree->value);
  if (tree->right != nullptr) {
    inOrderTraverse(tree->right, array);
  }
}

int main() {
  BST* tree = new BST(2);
  tree->left = new BST(1);
  tree->right = new BST(3);
  tree->left->left = new BST(4);
  tree->right->right = new BST(0);
  std::vector<int> expected = {0, 1, 2, 3, 4};
  BST* actual = repairBst(tree);
  std::vector<int> actualArray;
  inOrderTraverse(actual, actualArray);
  assert(actualArray == expected);
}
