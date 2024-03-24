
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

constexpr int md = int(1e9) + 7;

// kadane's algorithm
int max_sum_subarray(const std::vector<int>& list) {
  int current_sum = 0;
  int max_sum = 0;
  for (const int& element : list) {
    current_sum = (current_sum + element) % md;
    max_sum = std::max(max_sum, current_sum) % md;

    if (current_sum < 0) current_sum = 0;
  }

  return max_sum;
}

int main() {
  std::uint32_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint32_t n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    int max_sum_sa = max_sum_subarray(a);
    int max_sum = max_sum_sa;

    for (int i = 0; i < k; i++) {
      max_sum = (max_sum + max_sum_sa) % md;
    }

    std::cout << max_sum << std::endl;
  }
}
