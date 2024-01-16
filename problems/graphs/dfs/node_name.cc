#include <iostream>
#include <vector>

class Node {
public:
  char name;
  std::vector<Node *> children;

  Node(char name) : name(name){};

  // Time: O(v + e)
  // Space: O(v)
  // Call Stack (Frame): O(v)
  std::vector<char> depth_first_search(std::vector<char> &output) {

    output.push_back(name);

    if (!children.empty()) {
      for (Node *child : children) {
        child->depth_first_search(output);
      }
    }

    return output;
  }

  Node *add_child(char name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};

int main() {
  /*
   * node children
   * A    {B, C, D}
   * B    {E, F}
   */
  Node *graph = new Node('A');
  graph->add_child('B')->add_child('C')->add_child('D');

  for (Node *child : graph->children) {
    if (child->name == 'B')
      child->add_child('E')->add_child('F'); // B -> E, B -> F
    if (child->name == 'D')
      child->add_child('G')->add_child('H'); // D -> G, D -> H

    for (Node *sub_child : child->children) {
      if (sub_child->name == 'F')
        sub_child->add_child('I')->add_child('J'); // F -> I, F -> J
      if (sub_child->name == 'F')
        sub_child->add_child('I')->add_child('J'); // F -> I, F -> J
    }
  }
  /* graph->children[0]->add_child('E')->add_child('F');
  graph->children[2]->add_child('G')->add_child('H');
  graph->children[0]->children[1]->add_child('I')->add_child('J');
  graph->children[2]->children[0]->add_child('K'); */

  std::vector<char> result{};
  graph->depth_first_search(result);

  for (char element : result) {
    std::cout << element;
  }
}
