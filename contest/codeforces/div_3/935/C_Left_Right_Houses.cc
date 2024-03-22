
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::uint16_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint32_t n;
    std::cin >> n;

    std::string str;
    std::cin >> str;

    std::vector<double> satisfied(n + 1, 0);

    std::uint32_t zero_count = 0;
    std::uint32_t one_count = 0;

    for (int i = 0; i < n; i++) {
      if (str[i] == 0) zero_count++;
    }

    satisfied[0] = static_cast<double>(zero_count) / n;

    zero_count = 0;
    for (int i = 1; i <= n; i++) {
      if (str[i] == 0) {
        zero_count++;
        satisfied[i] = static_cast<double>(zero_count) / n;
      }
    }

    std::uint32_t satisfied_index = 0;
    double max_value = 0.0;

    for (int i = 0; i < n; i++) {
      if (satisfied[i] > max_value) {
        max_value = satisfied[i];
        satisfied_index = i;
      }
    }

    std::cout << satisfied_index << std::endl;
  }
}
