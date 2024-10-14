// ╔════════════════════════════════════════════════════════════════════╗
// ║ Competitive programming is not about solving problems.             ║
// ║ It's about continuously evolving your approach to problem-solving. ║
// ╚════════════════════════════════════════════════════════════════════╝
// author: Adam-Al-Rahman <https://atiq-urrehaman.netlify.app>
// Q: https://codeforces.com/contest/2022/problem/B

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
#include <algorithm>

// GLOBAL CONSTANTS EXPRESSIONS
namespace px {
inline constexpr std::int32_t mod = std::int32_t(1e9) + 7;  // Modulus
inline constexpr std::int32_t num = std::int32_t(2e5) + 5;
inline constexpr std::int32_t inf = 0x7FFFFFFF;  // prime: 2147483647
}  // namespace px

// PROBLEM KEYPOINTS

// ALIAS | STRUCT | CLASS | HELPER FUNCTIONS
namespace px {
using float32_t = float;
using float64_t = double;
using float128_t = long double;
using node = std::tuple<std::int64_t, std::int64_t>;  // NOTE: {high priority, low priority }

std::int64_t ceil(std::int64_t a, int64_t b) { return (a + b - 1) / b; }
}  // namespace px

// PROBLEM SOLUTION
void solution() {
  int n, k;
  std::cin >> n >> k;

  std::int64_t max = 0;
  std::int64_t sum = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    sum += x;
    if (max < x) max = x;
  }

  if (k == n) {
    std::cout << max << '\n';
    return;
  }

  if (k == 1) {
    std::cout << sum << '\n';
    return;
  }

  // Instead: use px::ceil
  // std::int64_t count = 0;
  // if (sum % k == 0)
  //   count = sum / k;
  // else
  //   count = (sum / k) + 1;

  std::cout << std::max(max, px::ceil(sum, k)) << '\n';
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
