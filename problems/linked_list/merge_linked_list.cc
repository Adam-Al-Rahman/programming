/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Merge Linked list
 * @brief:
 * @source:
 * @tags: ["topics/linked_list", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <cstdint>
#include <iostream>
#include <memory>

typedef class node : public std::enable_shared_from_this<node> {
 public:
  std::shared_ptr<node> next;
  std::int16_t value;

  node(int value, std::shared_ptr<node> next = nullptr)
      : value(value), next(next) {}

  void append(std::int16_t value) {
    std::shared_ptr<node> new_node = std::make_shared<node>(node(value));
    std::shared_ptr<node> current_node = shared_from_this();

    while (current_node->next != nullptr) {
      current_node = current_node->next;
    }

    current_node->next = new_node;
  }
} node_t;

std::shared_ptr<node_t> merge_list(std::shared_ptr<node_t> list_1,
                                   std::shared_ptr<node_t> list_2) {
  std::shared_ptr<node_t> list_1_ptr = list_1;
  std::shared_ptr<node_t> list_2_ptr = list_2;

  while (list_1_ptr != nullptr) {
    while (list_2_ptr != nullptr) {
      if (list_1_ptr->value == list_2_ptr->value) {
        return list_1_ptr;
      }

      list_2_ptr = list_2_ptr->next;
    }

    list_2_ptr = list_2;
    list_1_ptr = list_1_ptr->next;
  }

  return nullptr;
}

int main() {
  std::shared_ptr<node_t> list_1 = std::make_shared<node_t>(2);
  list_1->append(3);
  list_1->append(1);
  list_1->append(4);

  std::shared_ptr<node_t> list_2 = std::make_shared<node_t>(8);
  list_2->append(7);
  list_2->append(1);
  list_2->append(4);

  // merge list
  std::shared_ptr<node_t> merge_list_result = merge_list(list_1, list_2);

  std::cout << "List:" << std::endl;
  std::shared_ptr<node_t> current = merge_list_result;
  while (current != nullptr) {
    std::cout << current->value << " ";
    current = current->next;
  }
}
