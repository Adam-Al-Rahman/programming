// BST Construction

// Write a BST class for a Binary Search Tree. The class should support:
// Inserting values with the insert method.
// Removing values with the remove method; this method should only
// remove the first instance of a given value.
// Searching for values with the contains method.

// Note that you can't remove values from a single-node tree. In other words,
// calling the remove method on a single-node tree should simply not do
// anything.

// Each BST node has an integer value , a left child node, anda right
// child node. A node is said to be a valid BST node if and only if it satisfies the
// BST property: its value is strictly greater than the values of every node to its
// left; its value is less than or equal to the values of every node to its right;
// and its children nodes are either valid BST nodes themselves or None /
// null

#include <cassert>

// All operation Complexity
// Average: O(log(n)) time | O(1) space
// Worst: O(n) time | O(1) space
class BST {
 public:
  int value;
  BST* left;
  BST* right;

  explicit BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }

  BST& insert(int val) {
    BST* node = new BST(val);

    BST* current = this;
    while (current) {
      if (val < current->value) {
        if (current->left) {
          current = current->left;
        } else {
          current->left = node;
          break;
        }
      } else {
        if (current->right) {
          current = current->right;
        } else {
          current->right = node;
          break;
        }
      }
    }

    return *this;
  }

  bool contains(int val) {
    BST* current = this;

    while (current) {
      if (current->value == val)
        return true;
      else if (current->value > val)
        current = current->left;
      else
        current = current->right;
    }

    return false;
  }

  int get_min_val() {
    BST* current = this;
    while (current->left) current = current->left;
    return current->value;
  }

  void remove(int val, BST* parent = nullptr) {
    BST* current = this;

    while (current) {
      if (val < current->value) {
        parent = current;
        current = current->left;
      } else if (val > current->value) {
        parent = current;
        current = current->right;
      } else {
        if (current->left && current->right) {
          current->value = current->right->get_min_val();
          // current->value = smallest value of right subtree
          current->right->remove(current->value, current);
        } else if (!parent) {
          if (current->left) {
            current->value = current->left->value;
            current->right = current->left->right;
            current->left = current->left->left;
          } else if (current->right) {
            current->value = current->right->value;
            current->left = current->right->left;
            current->right = current->right->right;
          } else {
            current = nullptr;
          }
        } else if (parent->left == current) {
          parent->left = current->left ? current->left : current->right;
        } else if (parent->right == current) {
          parent->right = current->left ? current->left : current->right;
        }
        break;
      }
    }
  }
};

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

  root->insert(12);
  assert(root->right->left->left->value == 12);

  root->remove(10);
  assert(root->contains(10) == false);
  assert(root->value == 12);

  assert(root->contains(15));
}
