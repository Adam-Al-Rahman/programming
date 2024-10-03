// Copyright 2024 Adam-Al-Rahman
// Moore's Algorithm
// Majority Element

#include <iostream>
#include <vector>

int majority_element(std::vector<int>& elements) {
  int candidate;
  int count = 0;

  for (int x : elements) {
    if (count == 0) {
      candidate = x;
      count += 1;
    }

    if (x == candidate) count += 1;

    if (x != candidate) count -= 1;
  }

  // verify candidate
  count = 0;
  for (int x : elements) {
    if (x == candidate) count += 1;
  }

  // Return candidate if it occurs n/2 times, otherwise return -1
  return (count > elements.size() / 2) ? candidate : -1;
}

int main() {
  std::vector<int> elements = {1, 2, 3, 1, 4, 5, 6};
  std::cout << majority_element(elements);
}
