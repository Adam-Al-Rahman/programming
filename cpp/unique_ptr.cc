/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Unique Pointer
 * @brief:
 * @source:
 * @tags: ["topics/ownership", "algorithms/", "methods/unique_ptr"]
 * @status: solved
 */

/**
When you call get() on a std::unique_ptr, you obtain a raw pointer to the managed object. However, this raw pointer does
not participate in ownership; it's just a way to access the object's data directly without using smart pointer semantics
like -> or *.
*/

#include <iostream>
#include <memory>

// Node structure for the linked list
struct Node {
  int data;
  std::unique_ptr<Node> next;

  explicit Node(int val) : data(val), next(nullptr) {}
};

// Linked list class
class LinkedList {
 private:
  std::unique_ptr<Node> head;

 public:
  LinkedList() : head(nullptr) {}

  // Function to insert a new node at the end of the list
  void insert(int val) {
    std::unique_ptr<Node> newNode = std::make_unique<Node>(val);
    if (!head) {
      head = std::move(newNode);
    } else {
      Node* current = head.get();  // NOTE: Here `get()` create pointer to that specific node as reference
      while (current->next) {
        current = current->next.get();
      }
      current->next = std::move(newNode);
    }
  }

  // Function to traverse and print the linked list
  void traverse() const {
    Node* current = head.get();
    while (current) {
      std::cout << current->data << " ";
      current = current->next.get();
    }
    std::cout << std::endl;
  }
};

int main() {
  LinkedList myList;

  // Inserting elements into the linked list
  myList.insert(10);
  myList.insert(20);
  myList.insert(30);
  myList.insert(40);

  // Traversing and printing the linked list
  myList.traverse();

  return 0;
}
