// Copyright 2024 Adam-Al-Rahman
// Heap Permutations: Generate all permutation

#include <algorithm>
#include <vector>

void heap_permutation(std::vector<int>& list, int n, std::vector<std::vector<int>>& permutes) {
  if (n == 1) {
    permutes.push_back(list);
    return;
  }

  for (int i = 0; i < n; ++i) {
    heap_permutation(list, n - 1, permutes);

    // Swap back
    if (n % 2 == 0)
      std::swap(list[i], list[n - 1]);
    else
      std::swap(list[0], list[n - 1]);
  }
}
