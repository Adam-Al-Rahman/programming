/*
╔═══════════════════════════════════════════════╗
║                                               ║
║  Competitive programming is not about solving ║
║  problems; it's about continuously evolving   ║
║  your approach to problem-solving.            ║
║                                               ║
╚═══════════════════════════════════════════════╝

author: Adam-Al-Rahman <https://atiq-ur-rehaman.netlify.app>
*/

// HEADERS
#include <cstdint>
#include <cstdio>  // freopen
#include <ctime>   // std::clock
#include <ios>     // std::ios_base
#include <iostream>
#include <unordered_map>
#include <vector>

// GLOBAL CONSTANTS
constexpr std::int32_t MODULU = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t LARGE_NUM = 200005;

// PROBLEM KEYPOINTS
// * find two values (at distinct positions) whose sum is `x`.

// HELPER FUNCTIONS

// PROBLEM SOLUTION
void solution() {
  std::uint32_t n;
  std::cin >> n;

  std::uint32_t x;
  std::cin >> x;

  std::vector<std::uint32_t> a(n);
  for (std::int32_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::unordered_map<int, int> index_map;

  for (int i = 0; i < n; i++) {
    int complement = x - a[i];
    if (index_map.count(complement) > 0) {
      std::cout << index_map[complement] + 1 << ' ' << i + 1 << '\n';
      return;
    }

    index_map[a[i]] = i;
  }

  std::cout << "IMPOSSIBLE" << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("./test_zero/input.txt", "r", stdin);
  freopen("./test_zero/output.txt", "w", stdout);
#endif  // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  std::clock_t start_time = std::clock();
#endif  // ONLINE_JUDGE

  std::uint32_t tests = 1;
  // std::cin >> tests;  // overwrite
  while (tests--) solution();

#ifndef ONLINE_JUDGE
  std::clock_t end_time = std::clock();
  std::cerr << "Experimental Run Time(sec): "
            << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;
#endif  // ONLINE_JUDGE
}
