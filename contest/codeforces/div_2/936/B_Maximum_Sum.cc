
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

#define MODULO 1e9 + 7

int max_sum_subarray(const std::vector<int>& arr) {
  std::vector<int> subarrays;
  int max_sum_subarrays = 0;

  // Iterate through all possible subarray lengths
  for (size_t len = 1; len <= arr.size(); len++) {
    // Iterate through all starting positions for the current length
    for (size_t start = 0; start <= arr.size() - len; start++) {
      // Create a subarray using iterators and std::copy
      std::vector<int> subarray(len);
      std::copy(arr.begin() + start, arr.begin() + start + len,
                subarray.begin());
      int current_sum_subarrays =
          std::accumulate(subarray.begin(), subarray.end(), 0);

      if (max_sum_subarrays < current_sum_subarrays) {
        max_sum_subarrays = current_sum_subarrays;
        subarrays = subarray;
      }
    }
  }

  return (max_sum_subarrays % static_cast<int>(MODULO)) >= 0
             ? (max_sum_subarrays % static_cast<int>(MODULO))
             : 0;
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

    int max_sum = max_sum_subarray(a);

    for (int i = 0; i < k; i++) {
      max_sum = ((2 * max_sum) % static_cast<int>(MODULO));
    }

    std::cout << (max_sum % static_cast<int>(MODULO)) << std::endl;
  }
}
