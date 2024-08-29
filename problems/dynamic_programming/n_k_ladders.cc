// ╔════════════════════════════════════════════════════════════════════╗
// ║ Competitive programming is not about solving problems.             ║
// ║ It's about continuously evolving your approach to problem-solving. ║
// ╚════════════════════════════════════════════════════════════════════╝
// author: Adam-Al-Rahman <https://atiq-ur-rehaman.netlify.app>

// ONLINE_JUDGE
// #define ONLINE_JUDGE

// HEADERS (Required)
#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <cstdio>   // freopen
#include <ctime>    // std::clock
#include <ios>      // std::ios_base
#include <iostream>
#include <limits>  // std::numeric_limits
#include <tuple>   // std::tuple

// HEADERS (Current)
#include <vector>

// GLOBAL CONSTANTS EXPRESSIONS
namespace px {
constexpr std::int32_t mod = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t nums = std::int32_t(2e5) + 5;
constexpr std::int32_t inf = std::numeric_limits<std::int32_t>::max();

}  // namespace px

// PROBLEM KEYPOINTS

// HELPER FUNCTIONS | STRUCT | CLASS | ALIAS
namespace px {
using node = std::tuple<std::int64_t, std::int64_t>;  // NOTE: {high priority, low priority }

using float32_t = float;        // 32-bit floating-point type
using float64_t = double;       // 64-bit floating-point type
using float80_t = long double;  // Clang on x64 use 80bit (IEEE 754 Extended Precision)

}  // namespace px

int nk(int n, int k, std::vector<std::int64_t>& cache) {
  if (n < 0) return 0;

  if (cache[n] != -1) return cache[n];

  std::int64_t val = 0;
  for (std::int64_t i = 1; i <= k; ++i) val += nk(n - i, k, cache);

  return cache[n] = val;
}

// Dynamic Programming
int nk(int n, int k) {
  std::vector<std::int64_t> cache(n + 1, 0);
  cache[0] = 1;
  cache[1] = 1;

  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= k && (i - j >= 0); ++j) cache[i] += cache[i - j];
  }

  return cache[n];
}

// Dynamic Programming
// Sliding Window
int nk(int n, int k, bool use_sw) {
  std::vector<std::int64_t> cache(n + 1, 0);
  cache[0] = 1;
  cache[1] = 1;

  int prefix = 0;
  int ladder = 1 + 1;  // n0 + n1
  for (int i = 2; i <= k; ++i) {
    if (i <= k) {
      cache[i] = ladder;
      ladder += cache[i];
      continue;
    }

    cache[i] = cache[i - 1] + (cache[i - 1] - cache[prefix]);
    prefix += 1;
  }

  return cache[n];
}

// PROBLEM SOLUTION
void solution() {
  std::int64_t n, k;
  std::cin >> n >> k;

  std::vector<std::int64_t> cache(n + 1, -1);
  cache[0] = 1;
  cache[1] = 1;

  std::cout << nk(n, k) << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

#ifndef ONLINE_JUDGE
  (void)freopen("./zero/input.txt", "r", stdin);
  (void)freopen("./zero/output.txt", "w", stdout);
#endif  // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  std::clock_t start_time = std::clock();
#endif  // ONLINE_JUDGE

  std::uint32_t tests = 1;
  // std::cin >> tests;  // overwrite
  while (tests--) solution();

#ifndef ONLINE_JUDGE
  std::clock_t end_time = std::clock();
  std::cerr << "Experimental Run Time(sec): " << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;
#endif  // ONLINE_JUDGE
}
