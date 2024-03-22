
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  std::uint32_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint32_t n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int median_index = std::ceil(static_cast<double>(a.size()) / 2) - 1;

    int median_element = a[median_index];
    int median_element_count = 0;

    for (int i = median_index; i < n; i++) {
      if (a[i] != median_element) break;
      median_element_count++;
    }

    std::cout << median_element_count << '\n';
  }
}
