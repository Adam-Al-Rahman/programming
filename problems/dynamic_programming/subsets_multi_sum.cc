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
// Example:
// 1
// 4 3
// 1 2 5 9
// 7
// 10
// 4

// HELPER FUNCTIONS | STRUCT | CLASS | ALIAS
namespace px {
using node = std::tuple<std::int64_t, std::int64_t>;  // NOTE: {high priority, low priority }

using float32_t = float;   // 32-bit floating-point type
using float64_t = double;  // 64-bit floating-point type
}  // namespace px

// Using concept back-pointer
void find_subsets(int level, int sum_left, const std::vector<int>& a, std::vector<std::vector<int>>& cache,
                  std::vector<int>& current_subset, std::vector<std::vector<int>>& all_subsets) {
  // Pruning condition: if the current sum_left below 0
  if (sum_left < 0) return;

  // Base case: if we've processed all elements
  if (level == a.size()) {
    if (sum_left == 0) all_subsets.push_back(current_subset);  // Store the current valid subset
    return;
  }

  // Decision to skip the current element
  find_subsets(level + 1, sum_left, a, cache, current_subset, all_subsets);

  // Decision to include the current element
  current_subset.push_back(a[level]);  // Include the current element
  find_subsets(level + 1, sum_left - a[level], a, cache, current_subset, all_subsets);
  current_subset.pop_back();  // Backtrack
}

bool helper(int level, int sum_left, const std::vector<int>& a, std::vector<std::vector<int>>& cache) {
  // Pruning condition: if the current sum_left below 0
  if (sum_left < 0) return false;

  // Base case: if we've processed all elements
  if (level == a.size()) return sum_left == 0;

  // Cache check: return cached result if already computed
  if (cache[level][sum_left] != -1) return cache[level][sum_left];

  // Compute the result: either skip or take the current element
  bool ans = helper(level + 1, sum_left, a, cache) || helper(level + 1, sum_left - a[level], a, cache);

  // Store the result in the cache
  return cache[level][sum_left] = ans;
}

void solution() {
  int n, q;  //  q: # queries
  std::cin >> n >> q;

  // Input the array of elements
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  // Cache value, only once for all the queries
  std::vector<std::vector<int>> cache(n + 1, std::vector<int>(1000, -1));

  while (q--) {
    int t;  // t: target
    std::cin >> t;

    // Call helper to determine if the target sum can be formed
    if (helper(0, t, a, cache)) {
      std::vector<int> current_subset;
      std::vector<std::vector<int>> all_subsets;

      // Find and print all valid subsets
      find_subsets(0, t, a, cache, current_subset, all_subsets);
      for (const auto& subset : all_subsets) {
        for (int num : subset) std::cout << num << " ";
        std::cout << '\n';
      }
    } else {
      std::cout << -1 << '\n';  // Print -1 if no subset can form the target sum
    }
  }
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
