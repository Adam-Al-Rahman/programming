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
#include <algorithm>
#include <cstdint>
#include <cstdio>  // freopen
#include <ctime>   // std::clock
#include <ios>     // std::ios_base
#include <iostream>
#include <vector>

// GLOBAL CONSTANTS
constexpr std::int32_t MODULU = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t LARGE_NUM = 200005;

// PROBLEM KEYPOINTS

// HELPER FUNCTIONS

// PROBLEM SOLUTION
void solution() {
  std::int64_t n, k;
  std::cin >> n >> k;

  std::vector<std::int64_t> a(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];

  // --- Kadane's Algorithm
  std::int64_t max_sum = 0;
  std::int64_t total_sum = 0;
  std::int64_t current_sum = 0;

  for (int i = 0; i < n; i++) {
    total_sum += a[i];

    current_sum += a[i];
    current_sum = std::max(current_sum, std::int64_t(0));
    max_sum = std::max(max_sum, current_sum);
  }
  // ---

  total_sum = (total_sum % MODULU + MODULU) % MODULU;
  max_sum = max_sum % MODULU;

  std::int64_t t = 1;
  for (int i = 0; i < k; i++) {
    t = t * 2 % MODULU;
  }

  std::int64_t ans = (total_sum + max_sum * t - max_sum + MODULU) % MODULU;
  std::cout << ans << '\n';
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
  std::cin >> tests;  // overwrite
  while (tests--) solution();

#ifndef ONLINE_JUDGE
  std::clock_t end_time = std::clock();
  std::cerr << "Experimental Run Time(sec): "
            << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;
#endif  // ONLINE_JUDGE
}
