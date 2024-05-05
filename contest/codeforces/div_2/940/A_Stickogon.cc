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

// ONLINE_JUDGE
// #define ONLINE_JUDGE

// HEADERS
#include <cstdint>
#include <cstdio>  // freopen
#include <ctime>   // std::clock
#include <ios>     // std::ios_base
#include <iostream>
#include <vector>

// GLOBAL CONSTANTS EXPRESSIONS
constexpr std::int32_t MODULU = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t LARGE_NUM = std::int32_t(2e5) + 5;

// PROBLEM KEYPOINTS
// - find the maximum number of regular (equal-sided) polygons, simultaneously

// HELPER FUNCTIONS

// PROBLEM SOLUTION
void solution() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  std::vector<int> count(101, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    count[a[i]] += 1;
  }

  int max_c = 0;
  for (auto &v : count) {
    if (v >= 3) max_c += (v / 3);
  }

  std::cout << max_c << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("./zero/input.txt", "r", stdin);
  freopen("./zero/output.txt", "w", stdout);
#endif  // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  std::clock_t start_time = std::clock();
#endif  // ONLINE_JUDGE

  std::uint32_t tests = 1;
  std::cin >> tests;  // overwrite
  while (tests--) solution();

#ifndef ONLINE_JUDGE
  std::clock_t end_time = std::clock();
  std::cerr << "Experimental Run Time(sec): " << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;
#endif  // ONLINE_JUDGE
}
