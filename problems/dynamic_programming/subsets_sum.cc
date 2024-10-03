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

// Helper function for recursion with memoization
int helper(int level, int taken, int target, const std::vector<int>& a, std::vector<std::vector<int>>& cache) {
  // Pruning condition: if the current sum exceeds the target
  if (taken > target) return 0;

  // Base case: if we've processed all elements, check if the sum equals the target
  if (level == a.size()) return target == taken;

  // Cache check: return cached result if already computed
  if (cache[level][taken] != -1) return cache[level][taken];

  // Compute the result: either skip or take the current element
  int ans = helper(level + 1, taken, target, a, cache) || helper(level + 1, taken + a[level], target, a, cache);

  // Store the result in the cache
  return cache[level][taken] = ans;
}

// Solution function
void solution() {
  int n, t;
  std::cin >> n >> t;

  // Input the array of elements
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  // Dynamically sizing the cache based on input size
  int max_taken = t + 1;
  std::vector<std::vector<int>> cache(n, std::vector<int>(max_taken, -1));

  // Output the result of the helper function
  std::cout << helper(0, 0, t, a, cache) << '\n';
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
