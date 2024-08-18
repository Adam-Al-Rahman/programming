// Copyright 2024 Adam-Al-Rahman

/** Shift Linked List
Write a function that takes in the head ofa Singly Linked List and an integer k
shifts the list in place (i.e., doesn't create a brand new list) by k positions, and returns
its new head.

Shifting a Linked List means moving its nodes forward or backward and wrapping
them around the list where appropriate. For example, shifting a Linked List forward
by one position would make its tail become the new head of the linked list.

Whether nodes are moved forward or backward is determined by whether k is
positive or negative.

Each LinkedList node has an integer value as well asa next node pointing
to the next node in the list orto None / null if it's the tail of the list.

You can assume that the input Linked List will always have at least one node; in other
words, the head will never be None / nutl
*/

#include <cassert>
#include <cmath>
#include <cstdint>
#include <vector>

class LinkedList {
 public:
  int value;
  LinkedList* next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

std::vector<int> linkedListToArray(LinkedList* head) {
  std::vector<int> array{};
  auto current = head;
  while (current != nullptr) {
    array.push_back(current->value);
    current = current->next;
  }
  return array;
}

LinkedList* backward(LinkedList* head, int k) {
  LinkedList* slow = head;
  LinkedList* fast = head;

  while (k > 0) {
    slow = slow->next;
    --k;
  }

  while (fast != nullptr && fast->next != nullptr) fast = fast->next;

  LinkedList* new_head = slow->next;
  slow->next = nullptr;
  fast->next = head;

  return new_head;
}

LinkedList* shiftLinkedList(LinkedList* head, int k) {
  if (k == 0) return head;

  std::uint32_t r = std::abs(k);
  int size = 0;
  LinkedList* size_ll = head;

  while (size_ll != nullptr) {
    ++size;
    size_ll = size_ll->next;
  }

  if (r % size == 0) return head;  // k == size of list
  if (r > size) r %= size;

  // backward
  if (k < 0) return backward(head, r - 1);

  // forward
  LinkedList* slow = head;
  LinkedList* fast = head;

  while (r > 0 && fast != nullptr) {
    fast = fast->next;
    --r;
  }

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next;
  }

  LinkedList* new_head = slow->next;
  slow->next = nullptr;
  if (fast != nullptr) fast->next = head;

  return new_head;
}

int main() {
  auto head = new LinkedList(0);
  head->next = new LinkedList(1);
  head->next->next = new LinkedList(2);
  head->next->next->next = new LinkedList(3);
  head->next->next->next->next = new LinkedList(4);
  head->next->next->next->next->next = new LinkedList(5);
  auto result = shiftLinkedList(head, 2);
  auto array = linkedListToArray(result);

  std::vector<int> expected{4, 5, 0, 1, 2, 3};
  assert(expected == array);
}
