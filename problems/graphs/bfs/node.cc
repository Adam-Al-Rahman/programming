/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question:
 * @brief: Breadth First search
 * @source:
 * @tags: ["topics/graph", "algorithms/bfs", "methods/"]
 * @status: unsolved
 */

#include <queue>
#include <vector>

class Node {
 public:
  char name;
  std::vector<Node *> children;

  explicit Node(char name) : name(name) {}

  std::vector<char> breadth_first_search(std::vector<char> *array) {
    std::queue<Node *> to_process;
    to_process.push(this);

    while (!to_process.empty()) {
      Node *current = to_process.front();
      to_process.pop();

      array->push_back(current->name);

      for (Node *&child : current->children) {
        to_process.push(child);
      }
    }

    return *array;
  }
};
