// ╔════════════════════════════════════════════════════════════════════╗
// ║ Competitive programming is not about solving problems.             ║
// ║ It's about continuously evolving your approach to problem-solving. ║
// ╚════════════════════════════════════════════════════════════════════╝
// author: Adam-Al-Rahman <https://atiq-ur-rehaman.netlify.app>

// ONLINE_JUDGE
// #define ONLINE_JUDGE

// HEADERS (Required)
#ifndef ONLINE_JUDGE
#include <sys/resource.h>  // For getrusage
#endif                     // ONLINE_JUDGE

#include <array>
#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <cstdio>   // freopen
#include <ctime>    // std::clock
#include <ios>      // std::ios_base
#include <iostream>
#include <tuple>  // std::tuple

// HEADERS (Current)
#include <algorithm>  // std::fill
#include <array>
#include <vector>

// GLOBAL CONSTANTS EXPRESSIONS
namespace px {
inline constexpr std::int32_t mod = std::int32_t(1e9) + 7;  // Modulus
inline constexpr std::int32_t nums = std::int32_t(2e5) + 5;
inline constexpr std::int32_t inf = 0x7FFFFFFF;  // prime: 2147483647

}  // namespace px

// PROBLEM KEYPOINTS

// HELPER FUNCTIONS | STRUCT | CLASS | ALIAS
namespace px {
using node = std::tuple<std::int64_t, std::int64_t>;  // NOTE: {high priority, low priority }

using float32_t = float;   // 32-bit floating-point type
using float64_t = double;  // 64-bit floating-point type
}  // namespace px

std::array<std::array<std::array<int, 101>, 101>, 101> cache;

// level: current item in [0 ... n-1]
int helper(int level, int n, int x, int k, int time_taken, int item_taken, std::vector<int>& time,
           std::vector<int>& skill) {
  // pruning case

  // base case
  if (level == n) return 0;

  // cache check
  if (cache[level][time_taken][item_taken] != -1) return cache[level][time_taken][item_taken];

  // transition state
  int ways = helper(level + 1, n, x, k, time_taken, item_taken, time, skill);  // choice 1: don't take

  if ((time_taken + time[level] <= x) && (item_taken + 1 <= k)) {  // choice 2: take
    ways = std::max(
        ways, helper(level + 1, n, x, k, time_taken + time[level], item_taken, time, skill) + skill[level]);  // move
  }

  return cache[level][time_taken][item_taken] = ways;
}

// PROBLEM SOLUTION
void solution() {
  int n, x, k;
  std::cin >> n >> x >> k;

  std::vector<int> time(n);
  std::vector<int> skill(n);
  for (int i = 0; i < n; ++i) std::cin >> time[i] >> skill[i];

  std::vector<int> taken(n);
  for (auto& layer : cache) {
    for (auto& row : layer) std::fill(row.begin(), row.end(), -1);
  }

  std::cout << helper(0, n, x, k, 0, 0, time, skill) << '\n';
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
  // std::cin >> tests;  // overwrite
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
