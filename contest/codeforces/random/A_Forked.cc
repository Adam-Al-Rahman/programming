// ╔════════════════════════════════════════════════════════════════════╗
// ║ Competitive programming is not about solving problems.             ║
// ║ It's about continuously evolving your approach to problem-solving. ║
// ╚════════════════════════════════════════════════════════════════════╝
// author: Adam-Al-Rahman <https://atiq-ur-rehaman.netlify.app>
// Q: https://codeforces.com/problemset/problem/1904/A

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

// HELPER FUNCTIONS | STRUCT | CLASS | ALIAS
namespace px {
using node = std::tuple<std::int64_t, std::int64_t>;  // NOTE: {high priority, low priority }

using float32_t = float;   // 32-bit floating-point type
using float64_t = double;  // 64-bit floating-point type
}  // namespace px

// PROBLEM SOLUTION
void solution() {
  int a, b;
  std::cin >> a >> b;

  int xk, yk;
  std::cin >> xk >> yk;

  int xq, yq;
  std::cin >> xq >> yq;

  std::vector<px::node> king_death = {{xk + a, yk + b}, {xk + a, yk - b}, {xk - a, yk + b}, {xk - a, yk - b},
                                      {xk + b, yk + a}, {xk + b, yk - a}, {xk - b, yk + a}, {xk - b, yk - a}};

  std::vector<px::node> queen_death = {{xq + a, yq + b}, {xq + a, yq - b}, {xq - a, yq + b}, {xq - a, yq - b},
                                       {xq + b, yq + a}, {xq + b, yq - a}, {xq - b, yq + a}, {xq - b, yq - a}};

  // Sort the vector before applying std::unique
  std::sort(king_death.begin(), king_death.end());
  std::sort(queen_death.begin(), queen_death.end());

  // Remove duplicates using std::unique and erase
  king_death.erase(std::unique(king_death.begin(), king_death.end()), king_death.end());
  queen_death.erase(std::unique(queen_death.begin(), queen_death.end()), queen_death.end());

  int count = 0;
  for (auto &[kx, ky] : king_death) {
    for (auto &[qx, qy] : queen_death)
      if (kx == qx && ky == qy) count += 1;
  }

  std::cout << count << '\n';
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
