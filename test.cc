#include <cstdint>
#include <iostream>

int main() {
  std::uint32_t tests;

  while (tests--) {
    std::uint32_t n;
    std::cin >> n;

    if (n == 1) {
      std::cout << 6 << '\n' << std::flush;
    } else if (n & 1) {
      std::cout << (6 + (n / 2) + (2 * (n / 2) * 6)) << '\n' << std::flush;

    } else {
      std::cout << ((n / 2) + (2 * (n / 2) * 6)) << '\n' << std::flush;
    }
  }
}
