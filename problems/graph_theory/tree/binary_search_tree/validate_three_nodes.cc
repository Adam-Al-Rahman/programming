// Validate Three Nodes

// You're given three nodes that are contained in the same Binary Search Tree: nodeOne
// nodeTwo , and nodeThree . Write a function that returns a boolean representing whether one
// of nodeOne or nodeThree is an ancestor of nodeTwo and the other node is a descendant of
// nodeTwo . For example, if your function determines that nodeOne is an ancestor of nodeTwo
// then it needs to see if nodeThree is a descendant of nodeTwo . If your function determines
// that nodeThree is an ancestor, then it needs to see if nodeOne is a descendant.

// A descendant of a node N is defined as a node contained in the tree rooted at N . A node N is
// an ancestor of another node M if M is a descendant of N

// It isn't guaranteed that nodeOne or nodeThree will be ancestors or descendants of nodeTwo
// but it is guaranteed that all three nodes will be unique and will never be None null . In
// other words, you'll be given valid input nodes.

// Each BST node has an integer value , a left child node, anda right child node. A node is
// said to be a valid BST node if and only if it satisfies the BST property: its value is strictly
// greater than the values of every node to its left; its value is less than or equal to the values of
// every node to its right; and its children nodes are either valid BST nodes themselves or None

#include <cassert>

class BST {
 public:
  int value;
  BST* left = nullptr;
  BST* right = nullptr;

  BST(int value) { this->value = value; }
};

bool searchForTarget(BST* node, BST* target) {
  BST* currentNode = node;
  while (currentNode != nullptr && currentNode != target) {
    currentNode = target->value < currentNode->value ? currentNode->left : currentNode->right;
  }

  return currentNode == target;
}

// TC: O(d) | SC: O(1) | d: distance between nodeOne and nodeThree
bool validateThreeNodes(BST* nodeOne, BST* nodeTwo, BST* nodeThree) {
  BST* searchOne = nodeOne;
  BST* searchTwo = nodeThree;

  while (true) {
    bool foundThreeFromOne = searchOne == nodeThree;
    bool foundOneFromThree = searchTwo == nodeOne;
    bool foundNodeTwo = searchOne == nodeTwo || searchTwo == nodeTwo;
    bool finishedSearching = searchOne == nullptr && searchTwo == nullptr;

    if (foundThreeFromOne || foundOneFromThree || foundNodeTwo || finishedSearching) break;

    if (searchOne != nullptr) {
      searchOne = searchOne->value > nodeTwo->value ? searchOne->left : searchOne->right;
    }

    if (searchTwo != nullptr) {
      searchTwo = searchTwo->value > nodeTwo->value ? searchTwo->left : searchTwo->right;
    }
  }

  bool foundNodeFromOther = searchOne == nodeThree || searchTwo == nodeOne;
  bool foundNodeTwo = searchOne == nodeTwo || searchTwo == nodeTwo;
  if (!foundNodeTwo || foundNodeFromOther) return false;

  return searchForTarget(nodeTwo, searchOne == nodeTwo ? nodeThree : nodeOne);
}

int main() {
  BST* root = new BST(5);
  root->left = new BST(2);
  root->right = new BST(7);
  root->left->left = new BST(1);
  root->left->right = new BST(4);
  root->right->left = new BST(6);
  root->right->right = new BST(8);
  root->left->left->left = new BST(0);
  root->left->right->left = new BST(3);
  BST* nodeOne = root;
  BST* nodeTwo = root->left;
  BST* nodeThree = root->left->right->left;
  bool expected = true;
  auto actual = validateThreeNodes(nodeOne, nodeTwo, nodeThree);
  assert(expected == actual);
}
