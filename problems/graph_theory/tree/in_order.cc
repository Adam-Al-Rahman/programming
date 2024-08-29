// Copyright 2024 Adam-Al-Rahman

#include <iostream>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left, *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root) {
  if (root == nullptr) return;

  std::stack<TreeNode*> nodes;
  auto current = root;

  while (current != nullptr || !nodes.empty()) {
    // Reach the leftmost node of the current node
    while (current != nullptr) {
      nodes.push(current);
      current = current->left;
    }

    // Current must be nullptr at this point
    current = nodes.top();
    nodes.pop();
    std::cout << current->val << " ";

    // We have visited the node and its left subtree, now it's right subtree's turn
    current = current->right;
  }
}

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  inorderTraversal(root);  // Output: 4 2 5 1 3
}
