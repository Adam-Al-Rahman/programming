/*
 * Copyright 2024 Adam-Al-Rahman
 */

#include <stack>

class LinkedList {
 public:
  int value;
  LinkedList* next;

  explicit LinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

LinkedList* reverseLinkedList(LinkedList* head) {
  std::stack<LinkedList*> nodes;

  auto temp = head;
  while (temp) {
    nodes.push(temp);
    temp = temp->next;
  }

  head = nullptr;
  LinkedList* tail = nullptr;

  while (!nodes.empty()) {
    auto current = nodes.top();
    nodes.pop();

    if (!head) {
      head = current;
      tail = current;
    }

    tail->next = current;  // append current as last element;
    tail = current;        // point the tail to the current as current appended to the end of the head
  }

  if (tail) tail->next = nullptr;  // this one is obvious think it.

  return head;
}
