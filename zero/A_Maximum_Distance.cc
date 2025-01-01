// problem: https://codeforces.com/gym/102951/problem/A

// HEADERS
#ifndef ONLINE_JUDGE
#include <cstdio>  // freopen

#include "cpp-dump/cpp-dump.hpp"  // cpp_dump (debug)
#endif                            // ONLINE_JUDGE

#include <algorithm>
#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <ios>      // std::ios_base
#include <iostream>
#include <limits>
#include <vector>

// ALIAS | STRUCT | CLASS | HELPER FUNCTIONS
namespace px {
std::int64_t sq_ed(int x1, int x2, int y1, int y2) { return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1); }
}  // namespace px

// PROBLEM KEYPOINTS
void solution() {
  int n;
  std::cin >> n;

  std::vector<int> x(n);
  for (int i = 0; i < n; ++i) std::cin >> x[i];

  std::vector<int> y(n);
  for (int i = 0; i < n; ++i) std::cin >> y[i];

  std::int64_t mx = std::numeric_limits<std::int64_t>::min();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;

      mx = std::max(mx, px::sq_ed(x[i], x[j], y[i], y[j]));
    }
  }

  std::cout << mx << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

#ifndef ONLINE_JUDGE
  (void)freopen("./zero/input.txt", "r", stdin);
  (void)freopen("./zero/output.txt", "w", stdout);
#endif  // ONLINE_JUDGE

  std::uint32_t tests = 1;
  // std::cin >> tests;  // OVERWRITE
  while (tests--) solution();
}
