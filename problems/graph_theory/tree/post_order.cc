// Copyright 2024 Adam-Al-Rahman

#include <iostream>
#include <stack>
#include <vector>

// Definition for a binary tree node
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> post_order_traversal(TreeNode* root) {
  std::vector<int> result;
  if (!root) return result;

  std::stack<TreeNode*> nodes;
  TreeNode* last_visited = nullptr;
  TreeNode* current = root;

  while (!nodes.empty() || current != nullptr) {
    if (current != nullptr) {
      nodes.push(current);
      current = current->left;
    } else {
      TreeNode* peek_node = nodes.top();
      if (peek_node->right != nullptr && last_visited != peek_node->right) {
        current = peek_node->right;
      } else {
        result.push_back(peek_node->val);
        last_visited = peek_node;
        nodes.pop();
      }
    }
  }

  return result;
}

int main() {
  // Example tree:
  //     1
  //    / \
    //   2   3
  //  / \
    // 4   5

  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  std::vector<int> result = post_order_traversal(root);
  for (int val : result) {
    std::cout << val << " ";
  }
  // Output should be: 4 5 2 3 1
}
