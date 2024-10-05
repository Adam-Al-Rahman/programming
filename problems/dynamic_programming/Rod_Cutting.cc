// ╔════════════════════════════════════════════════════════════════════╗
// ║ Competitive programming is not about solving problems.             ║
// ║ It's about continuously evolving your approach to problem-solving. ║
// ╚════════════════════════════════════════════════════════════════════╝
// author: Adam-Al-Rahman <https://atiq-urrehaman.netlify.app>

// ONLINE_JUDGE
// #define ONLINE_JUDGE

// HEADERS (Required)
#ifndef ONLINE_JUDGE
#include <sys/resource.h>  // For getrusage
#endif                     // ONLINE_JUDGE

#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <cstdio>   // freopen
#include <ctime>    // std::clock
#include <ios>      // std::ios_base
#include <iostream>
#include <tuple>  // std::tuple

// HEADERS (Current)
#include <limits>
#include <vector>

// GLOBAL CONSTANTS EXPRESSIONS
namespace px {
inline constexpr std::int32_t mod = std::int32_t(1e9) + 7;  // Modulus
inline constexpr std::int32_t nums = std::int32_t(2e5) + 5;
inline constexpr std::int32_t inf = 0x7FFFFFFF;  // prime: 2147483647
}  // namespace px

// PROBLEM KEYPOINTS

// ALIAS | STRUCT | CLASS | HELPER FUNCTIONS
namespace px {
using float32_t = float;                              // 32-bit floating-point type
using float64_t = double;                             // 64-bit floating-point type
using node = std::tuple<std::int64_t, std::int64_t>;  // NOTE: {high priority, low priority }
}  // namespace px

int helper(int l, int r, const std::vector<int>& a, std::vector<std::vector<int>>& cache) {
  // Base Case
  if (l + 1 == r) return 0;

  // Cache check
  if (cache[l][r] != -1) return cache[l][r];

  // Transition
  int ans = std::numeric_limits<int>::max();

  for (int p = l + 1; p < r; p++) {
    ans = std::min(ans, (a[r] - a[l]) + helper(l, p, a, cache) + helper(p, r, a, cache));
  }

  return cache[l][r] = ans;
}

// PROBLEM SOLUTION
void solution() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  std::vector<std::vector<int>> cache(n + 1, std::vector<int>(n + 1, -1));

  std::cout << helper(0, n - 1, a, cache) << '\n';
}

// MAIN
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
  std::cin >> tests;  // overwrite
  while (tests--) solution();

#ifndef ONLINE_JUDGE
  std::clock_t end_time = std::clock();
  std::cerr << "Experimental Run Time (SEC): " << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;

  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  std::cerr << "Experimental Memory Usage (MB): " << (usage.ru_maxrss / 1024.0) << std::endl;
#endif  // ONLINE_JUDGE
}
