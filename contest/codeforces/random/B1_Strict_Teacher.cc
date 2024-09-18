// ╔════════════════════════════════════════════════════════════════════╗
// ║ Competitive programming is not about solving problems.             ║
// ║ It's about continuously evolving your approach to problem-solving. ║
// ╚════════════════════════════════════════════════════════════════════╝
// author: Adam-Al-Rahman <https://atiq-ur-rehaman.netlify.app>
// Q: https://codeforces.com/contest/2005/problem/B1

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
#include <cmath>
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

void helper(int n, int m, int d, std::vector<int>& teachers) {
  if (d < teachers.front()) {
    std::cout << teachers.front() - 1 << '\n';
    return;
  }

  if (d > teachers.back()) {
    std::cout << n - teachers.back() << '\n';
    return;
  }

  auto left_it = std::lower_bound(teachers.begin(), teachers.end(), d);
  // auto right_it = std::lower_bound(teachers.begin(), teachers.end(), d);
  auto right_it = left_it - 1;

  int mid_point = (*left_it + *right_it) / 2;
  int t1 = std::abs(mid_point - *left_it);
  int t2 = std::abs(*right_it - mid_point);
  std::cout << std::min(t1, t2) << '\n';
}

// PROBLEM SOLUTION
void solution() {
  int n, m, q;
  std::cin >> n >> m >> q;

  std::vector<int> teachers(m);
  for (int i = 0; i < m; ++i) std::cin >> teachers[i];

  std::vector<int> query(q);
  for (int i = 0; i < q; ++i) std::cin >> query[i];

  std::sort(teachers.begin(), teachers.end());

  for (int d : query) helper(n, m, d, teachers);
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
