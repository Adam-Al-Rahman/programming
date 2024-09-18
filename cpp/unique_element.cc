// Copyright 2024 Adam-Al-Rahman
// Inplace O(nlogn)

#include <algorithm>
#include <iostream>
#include <vector>

void remove_duplicates(std::vector<int>& vec) {
  // Step 1: Sort the vector
  std::sort(vec.begin(), vec.end());

  // Step 2: Use std::unique to move unique elements to the front
  auto last = std::unique(vec.begin(), vec.end());

  // Step 3: Resize the vector to remove trailing duplicates
  vec.erase(last, vec.end());
}

int main() {
  std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

  remove_duplicates(vec);

  for (int num : vec) {
    std::cout << num << " ";
  }

  return 0;
}
