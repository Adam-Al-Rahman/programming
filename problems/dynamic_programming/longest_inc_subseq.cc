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

#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <cstdio>   // freopen
#include <ctime>    // std::clock
#include <ios>      // std::ios_base
#include <iostream>
#include <tuple>  // std::tuple

// HEADERS (Current)
#include <algorithm>
#include <vector>

// GLOBAL CONSTANTS EXPRESSIONS
namespace px {
inline constexpr std::int32_t mod = std::int32_t(1e9) + 7;  // Modulus
inline constexpr std::int32_t nums = std::int32_t(2e5) + 5;
inline constexpr std::int32_t inf = 0x7FFFFFFF;  // prime: 2147483647
}  // namespace px

// PROBLEM KEYPOINTS
// Q. Find the longest increasing subsequence of array
// Example:
// 1
// 10
// 3 2 5 4 5 7 8 1 11 9

// HELPER FUNCTIONS | STRUCT | CLASS | ALIAS
namespace px {
using node = std::tuple<std::int64_t, std::int64_t>;  // NOTE: {high priority, low priority }

using float32_t = float;   // 32-bit floating-point type
using float64_t = double;  // 64-bit floating-point type
}  // namespace px

#include <algorithm>
#include <iostream>
#include <vector>

int helper(int level, std::vector<int>& a, std::vector<int>& cache) {
  // Base case
  if (level == 0) return 1;

  // Cache check
  if (cache[level] != -1) return cache[level];

  // Transition (default case: the subsequence contains at least one element)
  int ans = 1;

  for (int prev_taken = 0; prev_taken < level; ++prev_taken) {
    if (a[prev_taken] < a[level]) ans = std::max(ans, helper(prev_taken, a, cache) + 1);
  }

  // Save the result in the cache and return
  return cache[level] = ans;
}

std::vector<int> helper_optim(const std::vector<int>& a, int n) {
  std::vector<int> lis;
  std::vector<int> inserted_at(n);

  for (int i = 0; i < n; ++i) {
    if (lis.empty() || lis.back() < a[i]) {
      lis.push_back(a[i]);
      inserted_at[i] = lis.size() - 1;
    } else {
      auto it = std::lower_bound(lis.begin(), lis.end(), a[i]);
      *it = a[i];
      inserted_at[i] = it - lis.begin();
    }
  }

  std::vector<int> list;
  int current_len = lis.size() - 1;
  for (int i = n - 1; i >= 0; i -= 1) {
    if (inserted_at[i] == current_len) {
      list.push_back(a[i]);
      current_len -= 1;
    }
  }

  std::reverse(list.begin(), list.end());
  return list;
};

// PROBLEM SOLUTION
void solution() {
  int n;
  std::cin >> n;

  std::vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  // Cache initialized with -1 for memoization
  std::vector<int> cache(n, -1);

  // int lis = 0;
  // // Compute LIS ending at each index
  // for (int i = 0; i < n; ++i) lis = std::max(lis, helper(i, a, cache));
  // std::cout << lis << '\n';

  std::vector<int> list = helper_optim(a, n);
  for (auto x : list) std::cout << x << ' ';
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
