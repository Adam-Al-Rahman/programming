
// HEADERS
#ifndef ONLINE_JUDGE
#include <cstdio>  // freopen

#include "cpp-dump/cpp-dump.hpp"  // cpp_dump (debug)
#endif                            // ONLINE_JUDGE

#include <algorithm>
#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <ios>      // std::ios_base
#include <iostream>
#include <vector>

// ALIAS | STRUCT | CLASS | HELPER FUNCTIONS
namespace px {}

// PROBLEM KEYPOINTS
void solution() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

#ifndef ONLINE_JUDGE
  (void)freopen("diamond.in", "r", stdin);
  (void)freopen("diamond.out", "w", stdout);
#endif  // ONLINE_JUDGE

  std::uint32_t tests = 1;
  // std::cin >> tests;  // OVERWRITE
  while (tests--) solution();
}
