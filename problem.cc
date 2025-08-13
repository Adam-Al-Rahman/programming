
// HEADERS
#ifndef ONLINE_JUDGE
#include <cstdio>  // freopen

#include "cpp-dump/cpp-dump.hpp"  // cpp_dump (debug)
#endif                            // ONLINE_JUDGE

#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <ios>      // std::ios_base
#include <iostream>

// ALIAS | STRUCT | CLASS | HELPER FUNCTIONS
namespace px {}

// PROBLEM KEYPOINTS
void solution() {}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

#ifndef ONLINE_JUDGE
  (void)freopen("./input.txt", "r", stdin);
  (void)freopen("./output.txt", "w", stdout);
#endif  // ONLINE_JUDGE

  std::uint32_t tests = 1;
  std::cin >> tests;  // OVERWRITE
  while (tests--) solution();
}
