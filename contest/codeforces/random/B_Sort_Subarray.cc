// ╔════════════════════════════════════════════════════════════════════╗
// ║ Competitive programming is not about solving problems.             ║
// ║ It's about continuously evolving your approach to problem-solving. ║
// ╚════════════════════════════════════════════════════════════════════╝
// author: Adam-Al-Rahman <https://atiq-urrehaman.netlify.app>
// problem: https://codeforces.com/problemset/problem/1821/B

// HEADERS [Required]
#ifndef ONLINE_JUDGE
#include <sys/resource.h>  // For getrusage

#include <cstdio>  // freopen
#include <ctime>   // std::clock

#include "cpp-dump/cpp-dump.hpp"  // cpp_dump (debug)
#endif                            // ONLINE_JUDGE

#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <ios>      // std::ios_base
#include <iostream>
#include <tuple>  // std::tuple

// HEADERS [Current]
#include <vector>

// GLOBAL CONSTANTS EXPRESSIONS
namespace px {
inline constexpr std::int32_t mod = std::int32_t(1e9) + 7;  // Modulus
inline constexpr std::int32_t num_2e5 = std::int32_t(2e5) + 5;
inline constexpr std::int32_t num_2e9 = std::int32_t(2e9) + 7;
inline constexpr std::int64_t num_2e12 = std::int64_t(2e12) + 9;
inline constexpr std::int64_t num_2e18 = std::int64_t(2e18) + 9;
inline constexpr std::int32_t inf = 0x7FFFFFFF;  // prime: 2147483647
}  // namespace px

// PROBLEM KEYPOINTS

// ALIAS | STRUCT | CLASS | HELPER FUNCTIONS
namespace px {
using float32_t = float;
using float64_t = double;
using float128_t = long double;
using node = std::tuple<std::int64_t, std::int64_t>;  // NOTE: {high priority, low priority }
}  // namespace px

// PROBLEM SOLUTION
void solution() {
  int n;
  std::cin >> n;

  std::vector<int> a(n), b(n);
  for (int &x : a) std::cin >> x;
  for (int &x : b) std::cin >> x;

  int left = -1, right = -1;

  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      if (left == -1) left = i;
      right = i;
    }
  }

  if (left == -1) {
    std::cout << 1 << ' ' << n << '\n';
    return;
  }

  // Extend the range to the left and right while maintaining sorted order in b
  while (left > 0 && b[left - 1] <= b[left]) left -= 1;
  while (right < n - 1 && b[right] <= b[right + 1]) right += 1;

  std::cout << left + 1 << " " << right + 1 << "\n";  // +1: 1-Indexing
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
  std::cerr << "Empirical Run Time (SEC): " << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;

  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  std::cerr << "Empirical Memory Usage (MB): " << (usage.ru_maxrss / 1024.0) << std::endl;
#endif  // ONLINE_JUDGE
}
