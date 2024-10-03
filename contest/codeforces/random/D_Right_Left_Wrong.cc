// ╔════════════════════════════════════════════════════════════════════╗
// ║ Competitive programming is not about solving problems.             ║
// ║ It's about continuously evolving your approach to problem-solving. ║
// ╚════════════════════════════════════════════════════════════════════╝
// author: Adam-Al-Rahman <https://atiq-ur-rehaman.netlify.app>
// Q: https://codeforces.com/problemset/problem/2000/D

// ONLINE_JUDGE
// #define ONLINE_JUDGE

// HEADERS (Required)
#include <vector>
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

// PROBLEM SOLUTION
void solution() {
  int n;
  std::cin >> n;

  // for segment sum calculation
  std::vector<std::uint64_t> prefix_sum(n);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    if (i == 0)
      prefix_sum[i] = x;
    else
      prefix_sum[i] = (prefix_sum[i - 1] + x);
  }

  std::string s;
  std::cin >> s;

  std::vector<px::node> nodes;

  int i = 0;
  int j = n - 1;
  while (i < j) {
    if (s[i] == 'L' && s[j] == 'R') {
      nodes.push_back({i, j});
      i += 1;
      j -= 1;
    } else if (s[i] != 'L' && s[j] == 'R') {
      i += 1;
    } else if (s[i] == 'L' && s[j] != 'R') {
      j -= 1;
    } else {
      i += 1;
      j -= 1;
    }
  }

  std::uint64_t score = 0;
  for (const auto& [x, y] : nodes) {
    if (x == 0)
      score += prefix_sum[y];
    else
      score += (prefix_sum[y] - prefix_sum[x - 1]);
  }

  std::cout << score << '\n';
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
