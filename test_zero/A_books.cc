// HEADERS
#include <cstdint>
#include <cstdio>  // freopen
#include <ctime>
#include <ios>
#include <iostream>
#include <vector>

// GLOBAL CONSTANTS
constexpr std::int32_t MODULU = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t LARGE_NUM = 200005;

// HELPER FUNCTIONS

// PROBLEM SOLUTION
void solution() {
  std::uint32_t num_books;
  std::cin >> num_books;

  std::uint32_t time;
  std::cin >> time;

  std::vector<std::uint16_t> a(num_books);
  for (std::int32_t i = 0; i < num_books; i++) {
    std::cin >> a[i];
  }

  std::cout << "Time: " << time << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);  // tie() is a method that simply guarantees the flushing of
                    // std::cout before std::cin accepts an input. For
                    // INTERACTIVE PROBLEM
  std::cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("./test_zero/input.txt", "r", stdin);
  freopen("./test_zero/output.txt", "w", stdout);
#endif  // ONLINE_JUDGE

  std::clock_t start_time = std::clock();

  std::uint32_t tests = 1;
  // std::cin >> tests;  // overwrite
  while (tests--) solution();

  std::clock_t end_time = std::clock();
  std::cerr << "Run Time(sec): "
            << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;
}
