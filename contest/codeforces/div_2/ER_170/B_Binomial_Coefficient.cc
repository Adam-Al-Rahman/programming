// ╔════════════════════════════════════════════════════════════════════╗
// ║ Competitive programming is not about solving problems.             ║
// ║ It's about continuously evolving your approach to problem-solving. ║
// ╚════════════════════════════════════════════════════════════════════╝
// author: Adam-Al-Rahman <https://atiq-urrehaman.netlify.app>
// Q: https://codeforces.com/contest/2025/problem/B

// ONLINE_JUDGE
// #define ONLINE_JUDGE

// HEADERS (Required)
#ifndef ONLINE_JUDGE
#include <sys/resource.h>  // For getrusage

#include <cstdio>  // freopen
#include <ctime>   // std::clock
#endif             // ONLINE_JUDGE

#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <ios>      // std::ios_base
#include <iostream>
#include <tuple>  // std::tuple

// HEADERS (Current)
#include <vector>

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
}  // namespace px

// PROBLEM SOLUTION
void solution() {
  int t;
  std::cin >> t;

  std::vector<int> n(t);
  for (int i = 0; i < t; ++i) std::cin >> n[i];

  std::vector<int> k(t);
  for (int i = 0; i < t; ++i) std::cin >> k[i];

  // for (int n = 0; n < N; n++) {  // loop over n from 0 to N-1 (inclusive)
  //   C[n][0] = 1;
  //   C[n][n] = 1;
  //   for (int k = 1; k < n; k++)  // loop over k from 1 to n-1 (inclusive)
  //     C[n][k] = C[n][k - 1] + C[n - 1][k - 1];
  // }
  std::vector<int> C(px::num, 1);
  for (int i = 1; i <= px::num; i++) C[i] = (2 * C[i - 1]) % px::mod;

  for (int i = 0; i < t; ++i) std::cout << C[k[i]] << '\n';
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
