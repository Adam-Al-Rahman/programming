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
#include <algorithm>
#include <climits>

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

int helper(int i, int j, const std::vector<px::node>& directions, const std::vector<std::vector<int>>& matrix,
           std::vector<std::vector<int>>& cache) {
  // Base case
  if (i == matrix.size() - 1 && j == matrix[0].size() - 1) return matrix[i][j];

  // Cache check
  // Instead Use visisted[i][j] to check along with cache[i][j]
  // If # Negative values <= (n * m) / 2 use hashmap[{i,j}] return bool
  if (cache[i][j] != INT_MIN) return cache[i][j];

  // Transition
  int current = INT_MIN;
  for (const auto& [dx, dy] : directions) {
    if (i + dx < matrix.size() && j + dy < matrix.size())
      current = std::max(current, helper(i + dx, j + dy, directions, matrix, cache) + matrix[i][j]);
  }

  return cache[i][j] = current;
}

// PROBLEM SOLUTION
void solution() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) std::cin >> matrix[i][j];
  }

  std::vector<px::node> directions = {{0, 1}, {1, 0}};
  std::vector<std::vector<int>> caches(n, std::vector<int>(m, INT_MIN));
  std::cout << helper(0, 0, directions, matrix, caches);
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
