// Max Path Sum Binary Tree

// Write a function that takes in a Binary Tree and returns its max path sum.
// A path is a collection of connected nodes in a tree, where no node is connected to more
// than two other nodes; a path sum is the sum of the values of the nodes in a particular path.
// Each BinaryTree node has an integer value , a left child node, anda right child
// node. Children nodes can either be BinaryTree nodes themselves or None / null

#include <cassert>
#include <cstdio>
#include <deque>
#include <vector>

class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value);
  void insert(std::vector<int> values, int i = 0);
};

BinaryTree::BinaryTree(int value) {
  this->value = value;
  this->left = nullptr;
  this->right = nullptr;
}

void BinaryTree::insert(std::vector<int> values, int i) {
  if (i >= values.size()) return;

  std::deque<BinaryTree*> queue;
  queue.push_back(this);

  while (queue.size() > 0) {
    BinaryTree* current = queue.front();
    queue.pop_front();

    if (current->left == nullptr) {
      current->left = new BinaryTree(values[i]);
      break;
    }

    queue.push_back(current->left);
    if (current->right == nullptr) {
      current->right = new BinaryTree(values[i]);
      break;
    }

    queue.push_back(current->right);
  }

  this->insert(values, i + 1);
}

#include <algorithm>
#include <limits>
#include <tuple>

namespace px {
using node = std::tuple<int, int>;
constexpr int min = std::numeric_limits<int>::min();
}  // namespace px

px::node max_sum_val(BinaryTree* tree) {
  if (!tree) return std::make_tuple(0, 0);

  auto [left_sum_branch, left_sum] = std::make_tuple(0, px::min);
  if (tree->left) std::tie(left_sum_branch, left_sum) = max_sum_val(tree->left);

  auto [right_sum_branch, right_sum] = std::make_tuple(0, px::min);
  if (tree->right) std::tie(right_sum_branch, right_sum) = max_sum_val(tree->right);

  int max_child_sum_path = std::max(left_sum_branch, right_sum_branch);
  int max_sum_branch = std::max(tree->value, max_child_sum_path + tree->value);
  int max_sum_triangle = std::max(max_sum_branch, left_sum_branch + tree->value + right_sum_branch);
  int running_max_path_sum = std::max({max_sum_triangle, left_sum, right_sum});

  return std::make_tuple(max_sum_branch, running_max_path_sum);
}

int maxPathSum(BinaryTree tree) {
  auto [_, max_path_sum] = max_sum_val(&tree);
  return max_path_sum;
}

int main() {
  BinaryTree test(1);
  test.insert({2, 3, 4, 5, 6, 7});
  assert(maxPathSum(test) == 18);
}
