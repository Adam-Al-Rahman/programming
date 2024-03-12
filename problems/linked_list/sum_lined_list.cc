/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Sum linked
 *
 * list
 * @brief:
 * @source:
 * @tags: ["topics/linked_list", "algorithms/",

 * * "methods/"]
 * @status: unsolved
 */

/**
 * # linked list: 2
 * len: unequal
 * LL represent: non-negative integer

 * *
 * each node: integer
 * first node: least significant digit
 * return a
 * new
 * linked list with sum of two linked list value
 *
 */

#include <algorithm>
#include <iostream>
#include <string>

class Node {
 public:
  int value;
  Node* next;

  explicit Node(int value) : value(value), next(nullptr) {}

  // Function to append a new node at the end of the linked list
  void append(int value) {
    Node* end = new Node(value);
    Node* n = this;
    while (n->next != nullptr) {
      n = n->next;
    }
    n->next = end;
  }
};

Node* sum_linked_list(Node* ll_first, Node* ll_second) {
  std::string ll_first_str;
  std::string ll_second_str;

  // Convert linked list to string representation
  Node* temp = ll_first;
  while (temp != nullptr) {
    ll_first_str += std::to_string(temp->value);
    temp = temp->next;
  }

  temp = ll_second;
  while (temp != nullptr) {
    ll_second_str += std::to_string(temp->value);
    temp = temp->next;
  }

  // Reverse the strings to get the correct order for addition
  std::reverse(ll_first_str.begin(), ll_first_str.end());
  std::reverse(ll_second_str.begin(), ll_second_str.end());

  // Convert the sum back to a string and reverse it to maintain the list order
  std::string sum_str =
      std::to_string((std::stoi(ll_first_str) + std::stoi(ll_second_str)));

  // Create a new linked list for the sum
  Node* ll_sum = nullptr;
  Node* current = nullptr;

  // Add each digit to the linked list
  for (const char& digit : sum_str) {
    int number = digit - '0';  // Convert char to int

    if (ll_sum == nullptr) {
      ll_sum = new Node(number);
      current = ll_sum;
    } else {
      current->append(number);
      current = current->next;
    }
  }

  return ll_sum;
}

int main() {
  Node* ll_first = new Node(2);
  ll_first->append(4);
  ll_first->append(7);
  ll_first->append(1);

  Node* ll_second = new Node(9);
  ll_second->append(4);
  ll_second->append(5);

  Node* ll_sum = sum_linked_list(ll_first, ll_second);

  Node* current = ll_sum;
  while (current != nullptr) {
    std::cout << current->value << " ";
    current = current->next;
  }

  return 0;
}
