/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Remove duplicates from linked list
 * @brief:
 * @source:
 * @tags: ["topics/linked_list", "algorithms/", "methods/hash_map"]
 * @status: unsolved
 */

#include <cstdint>
#include <iostream>
#include <memory>
#include <unordered_map>

/**

In the given code:

```cpp
if (unique_elements[current->value] == true) {
    prev->next = current->next;
    current.reset();  // This releases shared ownership and potentially deletes
the node current = prev->next; continue;
}
```

When `current.reset()` is called, it releases the shared ownership of the node
that `current` was pointing to. However, since `prev->next` has been modified to
skip the current node (`prev->next = current->next;`), the ownership release
does not directly affect the original linked list.

The deletion of the node will occur if and only if there are no other shared
pointers holding ownership of that specific node. If `current` was the last
shared pointer owning the node, the node will be deleted. The `reset()` call
ensures that the shared ownership held by `current` is released, and the
destruction of the node occurs if there are no other shared pointers owning it.

I appreciate your patience, and I hope this clarification helps.
*/

typedef struct node {
 public:
  std::shared_ptr<node> next;
  int value;

  node(int value, std::shared_ptr<node> next = nullptr)
      : value(value), next(next) {}
} node_t;

std::shared_ptr<node_t> remove_duplicate(std::shared_ptr<node_t> head) {
  std::unordered_map<std::int64_t, bool> unique_elements;

  std::shared_ptr<node_t> prev = head;
  std::shared_ptr<node_t> current = head->next;

  while (current != nullptr) {
    unique_elements[prev->value] = true;

    if (unique_elements[current->value] == true) {
      prev->next = current->next;
      current.reset();
      current = prev->next;
      continue;
    }

    prev = current;
    current = current->next;
  }

  return std::make_shared<node>(head->value, head->next);
}

int main() {
  std::shared_ptr<node_t> head = std::make_shared<node_t>(1);
  head->next = std::make_shared<node_t>(2);
  head->next->next = std::make_shared<node_t>(3);
  head->next->next->next = std::make_shared<node_t>(2);
  head->next->next->next->next = std::make_shared<node_t>(4);
  head->next->next->next->next->next = std::make_shared<node_t>(3);

  std::cout << "Original linked list:" << std::endl;
  std::shared_ptr<node_t> current = head;
  while (current != nullptr) {
    std::cout << current->value << " ";
    current = current->next;
  }
  std::cout << std::endl;

  // Remove duplicates
  std::shared_ptr<node_t> modifiedHead = remove_duplicate(head);

  std::cout << "Linked list after removing duplicates:" << std::endl;
  current = modifiedHead;
  while (current != nullptr) {
    std::cout << current->value << " ";
    current = current->next;
  }
  std::cout << std::endl;

  return 0;
}
