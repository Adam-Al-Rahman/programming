
// K - ary tree
// Binary tree, k = 2
/*
 *     1
 *    / \
 *   2   3
 *    \
 *     5
 */

class Node {
public:
  int data;
  Node* left;
  Node* right;
  
  Node(int data) : data(data), left(nullptr), right(nullptr){};
};

int main(){
  Node* root = new Node(1);
  (*root).left = new Node(2); // root->left is same as (*root).left
  (*root).right = new Node(3);
  root->left->right = new Node(5);
}
