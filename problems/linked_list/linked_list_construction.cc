// Linked List Construction

// Write a DoublyLinkedList class that has a head anda tail , both of which point to either
// a linked list Node or None / null . The class should support:
// - Setting the head and tail of the linked list.
// - Inserting nodes before and after other nodes as well as at given positions (the position of the head node is 1 ).
// - Removing given nodes and removing nodes with given values.
// - Searching for nodes with given values.

// Note that the setHead , setTaiI , insertBefore , insertAfter , insertAtPosition ,
// and remove methods all take in actual Node s as input parameters—not integers (except for
// i nsertAtPosition , which also takes in an integer representing the position); this means that
// you don't need to create any new Node s in these methods. The input nodes can be either
// stand-alone nodes or nodes that are already in the linked list. If they're nodes that are already in
// the linked list, the methods will effectively be movingthe nodes within the linked list. You won't
// be told if the input nodes are already in the linked list, so your code will have to defensively
// handle this scenario.

// If you're doing this problem in an untyped language like Python or JavaScript, you may want to
// look at the various function signatures in a typed language like Java or TypeScript to get a better
// idea of what each input parameter is.

// Each Node has an integer value as well asa prev node anda next node, both of which
// can point to either another node or None / null

#include <cassert>
#include <vector>

class Node {
 public:
  int value;
  Node* prev;
  Node* next;

  Node(int value);
};

class DoublyLinkedList {
 public:
  Node* head;
  Node* tail;

  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  // TC: O(1) | SC: O(!)
  void setHead(Node* node) {
    if (head == nullptr) {
      head = node;
      tail = node;
      return;
    }

    insertBefore(head, node);
  }

  void setTail(Node* node) {
    if (tail == nullptr) {
      setHead(node);
      return;
    }

    insertAfter(tail, node);
  }

  // TC: O(1) | SC: O(1)
  void insertBefore(Node* node, Node* nodeToInsert) {
    if (nodeToInsert == head && nodeToInsert == tail) return;
    remove(nodeToInsert);
    nodeToInsert->prev = node->prev;
    nodeToInsert->next = node;
    if (node->prev == nullptr)
      head = nodeToInsert;
    else
      node->prev->next = nodeToInsert;

    node->prev = nodeToInsert;
  }

  // TC: O(1) | SC: O(1)
  void insertAfter(Node* node, Node* nodeToInsert) {
    if (nodeToInsert == head && nodeToInsert == tail) return;
    remove(nodeToInsert);
    nodeToInsert->prev = node;
    nodeToInsert->next = node->next;

    if (node->next == nullptr)
      tail = nodeToInsert;
    else
      node->next->prev = nodeToInsert;
    node->next = nodeToInsert;
  }

  // TC: O(p) | SC: O(1)
  void insertAtPosition(int position, Node* nodeToInsert) {
    if (position == 1) {
      setHead(nodeToInsert);
      return;
    }

    Node* node = head;
    int currentPosition = 1;
    while (node != nullptr && currentPosition++ != position) node = node->next;

    if (node != nullptr)
      insertBefore(node, nodeToInsert);
    else
      setTail(nodeToInsert);
  }

  // TC: O(n) | SC: O(1)
  void removeNodesWithValue(int value) {
    Node* node = head;

    while (node != nullptr) {
      Node* nodeToRemove = node;
      node = node->next;
      if (nodeToRemove->value == value) remove(nodeToRemove);
    }
  }

  // TC: O(1) | SC: O(1)
  void remove(Node* node) {
    if (node == head) head = head->next;
    if (node == tail) tail = tail->next;

    removeNodeBindings(node);
  }

  // TC: O(n) | SC: O(1)
  bool containsNodeWithValue(int value) {
    Node* node = head;
    while (node != nullptr && node->value != value) node = node->next;
    return node != nullptr;
  }

  void removeNodeBindings(Node* node) {
    if (node->prev != nullptr) node->prev->next = node->next;
    if (node->next != nullptr) node->next->prev = node->prev;
    node->prev = nullptr;
    node->next = nullptr;
  }
};

Node::Node(int value) {
  this->value = value;
  prev = nullptr;
  next = nullptr;
};

vector<int> getNodeValuesHeadToTail(DoublyLinkedList linkedList) {
  vector<int> values = {};
  Node* node = linkedList.head;
  while (node != nullptr) {
    values.push_back(node->value);
    node = node->next;
  }
  return values;
}

vector<int> getNodeValuesTailToHead(DoublyLinkedList linkedList) {
  vector<int> values = {};
  Node* node = linkedList.tail;
  while (node != nullptr) {
    values.push_back(node->value);
    node = node->prev;
  }
  return values;
}

void bindNodes(Node* nodeOne, Node* nodeTwo) {
  nodeOne->next = nodeTwo;
  nodeTwo->prev = nodeOne;
}

int main() {
  DoublyLinkedList linkedList;
  Node one(1);
  Node two(2);
  Node three(3);
  Node three2(3);
  Node three3(3);
  Node four(4);
  Node five(5);
  Node six(6);
  bindNodes(&one, &two);
  bindNodes(&two, &three);
  bindNodes(&three, &four);
  bindNodes(&four, &five);
  linkedList.head = &one;
  linkedList.tail = &five;

  linkedList.setHead(&four);
  assert(getNodeValuesHeadToTail(linkedList) == (std::vector<int>{4, 1, 2, 3, 5}));
  assert(getNodeValuesTailToHead(linkedList) == (std::vector<int>{5, 3, 2, 1, 4}));

  linkedList.setTail(&six);
  assert(getNodeValuesHeadToTail(linkedList) == (std::vector<int>{4, 1, 2, 3, 5, 6}));
  assert(getNodeValuesTailToHead(linkedList) == (std::vector<int>{6, 5, 3, 2, 1, 4}));

  linkedList.insertBefore(&six, &three);
  assert(getNodeValuesHeadToTail(linkedList) == (std::vector<int>{4, 1, 2, 5, 3, 6}));
  assert(getNodeValuesTailToHead(linkedList) == (std::vector<int>{6, 3, 5, 2, 1, 4}));

  linkedList.insertAfter(&six, &three2);
  assert(getNodeValuesHeadToTail(linkedList) == (std::vector<int>{4, 1, 2, 5, 3, 6, 3}));
  assert(getNodeValuesTailToHead(linkedList) == (std::vector<int>{3, 6, 3, 5, 2, 1, 4}));

  linkedList.insertAtPosition(1, &three3);
  assert(getNodeValuesHeadToTail(linkedList) == (std::vector<int>{3, 4, 1, 2, 5, 3, 6, 3}));
  assert(getNodeValuesTailToHead(linkedList) == (std::vector<int>{3, 6, 3, 5, 2, 1, 4, 3}));

  linkedList.removeNodesWithValue(3);
  assert(getNodeValuesHeadToTail(linkedList) == (std::vector<int>{4, 1, 2, 5, 6}));
  assert(getNodeValuesTailToHead(linkedList) == (std::vector<int>{6, 5, 2, 1, 4}));

  linkedList.remove(&two);
  assert(getNodeValuesHeadToTail(linkedList) == (std::vector<int>{4, 1, 5, 6}));
  assert(getNodeValuesTailToHead(linkedList) == (std::vector<int>{6, 5, 1, 4}));

  assert(linkedList.containsNodeWithValue(5) == true);
}
