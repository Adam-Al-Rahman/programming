/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Find loop
 * @brief:
 * @source:
 * @tags: ["topics/linked_list", "algorithms/", "methods/"]
 * @status: solved
 */

#include <iostream>
#include <vector>

class LinkedList {
 public:
  int value;
  LinkedList* next;

  explicit LinkedList(int value) : value(value), next(nullptr) {}
};

void addMany(LinkedList* ll, std::vector<int> values) {
  LinkedList* current = ll;
  while (current->next != nullptr) {
    current = current->next;
  }
  for (int value : values) {
    current->next = new LinkedList(value);
    current = current->next;
  }
}

LinkedList* getNthNode(LinkedList* ll, int n) {
  int counter = 1;
  LinkedList* current = ll;
  while (counter < n) {
    current = current->next;
    counter++;
  }
  return current;
}

LinkedList* find_loop(LinkedList* head) {
  if (head == nullptr || head->next == nullptr)
    return nullptr;  // no loop if the list has 0 or 1 nodes

  LinkedList* slow = head->next;
  LinkedList* fast = head->next->next;

  while (slow != fast) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // NOTE: never forget to check this
  if (fast == nullptr || fast->next == nullptr) return nullptr;  // no loop

  slow = head;
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }

  return slow;
}

int main() {
  LinkedList test(0);
  addMany(&test, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  getNthNode(&test, 10)->next = getNthNode(&test, 5);

  std::cout << "Result: " << (find_loop(&test) == getNthNode(&test, 5));
}
