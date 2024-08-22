// ╔════════════════════════════════════════════════════════════════════╗
// ║ Competitive programming is not about solving problems.             ║
// ║ It's about continuously evolving your approach to problem-solving. ║
// ╚════════════════════════════════════════════════════════════════════╝
// author: Adam-Al-Rahman <https://atiq-ur-rehaman.netlify.app>
// Q: https://codeforces.com/problemset/problem/489/B

// ONLINE_JUDGE
// #define ONLINE_JUDGE

// HEADERS (Required)
#include <algorithm>
#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <cstdio>   // freopen
#include <cstdlib>
#include <ctime>  // std::clock
#include <ios>    // std::ios_base
#include <iostream>
#include <tuple>  // std::tuple

// HEADERS (Current)
#include <algorithm>
#include <cstdlib>
#include <vector>

// GLOBAL CONSTANTS EXPRESSIONS
namespace px {
constexpr std::int32_t mod = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t num = std::int32_t(2e5) + 5;
}  // namespace px

// PROBLEM KEYPOINTS

// HELPER FUNCTIONS | STRUCT | CLASS | ALIAS
namespace px {
using node = std::tuple<std::int64_t, std::int64_t>;  // NOTE: {high priority, low priority }

using float32_t = float;        // 32-bit floating-point type
using float64_t = double;       // 64-bit floating-point type
using float80_t = long double;  // Clang on x64 use 80bit (IEEE 754 Extended Precision)

}  // namespace px

// PROBLEM SOLUTION
void solution() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  int m;
  std::cin >> m;

  std::vector<int> b(m);
  for (int i = 0; i < m; ++i) std::cin >> b[i];

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  int count = 0;
  int i = 0;
  int j = 0;

  while (i < n && j < m) {
    int diff = std::abs(a[i] - b[j]);

    if (diff <= 1) {
      ++count;
      ++i;
      ++j;
    } else if (a[i] < b[j]) {
      ++i;
    } else {
      ++j;
    }
  }

  std::cout << count << '\n';
}

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
  std::cerr << "Experimental Run Time(sec): " << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;
#endif  // ONLINE_JUDGE
}
