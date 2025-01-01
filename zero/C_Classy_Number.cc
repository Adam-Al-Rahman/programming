// problem: https://codeforces.com/contest/1036/problem/C

// HEADERS
#include <string>
#ifndef ONLINE_JUDGE
#include <cstdio>  // freopen

#include "cpp-dump/cpp-dump.hpp"  // cpp_dump (debug)
#endif                            // ONLINE_JUDGE

#include <array>
#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <ios>      // std::ios_base
#include <iostream>
#include <string>

// ALIAS | STRUCT | CLASS | HELPER FUNCTIONS
namespace px {
std::int64_t fn(int idx, int tight, int num, const std::string& s,
                std::array<std::array<std::array<std::int64_t, 4>, 2>, 20>& cache) {
  if (idx == s.size()) return (num <= 3) ? 1 : 0;

  if (cache[idx][tight][num] != -1) return cache[idx][tight][num];

  std::int64_t sum = 0;
  int bound = (tight ? s[idx] - '0' : 9);

  for (int i = 0; i <= bound; ++i) {
    int new_num = num + (i != 0);
    if (new_num > 3) continue;

    sum += px::fn(idx + 1, tight && (i == bound), new_num, s, cache);
  }

  return cache[idx][tight][num] = sum;
}

std::int64_t count(const std::string& n, std::array<std::array<std::array<std::int64_t, 4>, 2>, 20>& cache) {
  for (auto& outer : cache) {
    for (auto& inner : outer) {
      std::fill(inner.begin(), inner.end(), -1);
    }
  }

  return px::fn(0, 1, 0, n, cache);
}
}  // namespace px

// PROBLEM KEYPOINTS
void solution() {
  std::string l, r;
  std::cin >> l >> r;

  std::array<std::array<std::array<std::int64_t, 4>, 2>, 20> cache;

  std::int64_t count_l = px::count(l, cache);
  std::int64_t count_r = px::count(r, cache);

  int count = 0;
  for (char c : l) {
    if (c != '0') count += 1;
  }

  std::cout << count_r - count_l + (count <= 3) << '\n';
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
  std::cin >> tests;  // OVERWRITE
  while (tests--) solution();
}
