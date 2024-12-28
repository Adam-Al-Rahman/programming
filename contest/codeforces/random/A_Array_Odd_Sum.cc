// problem: https://codeforces.com/problemset/problem/1296/A

// HEADERS [Required]
#ifndef ONLINE_JUDGE
#include <sys/resource.h>  // For getrusage

#include <cstdio>  // freopen
#include <ctime>   // std::clock

#include "cpp-dump/cpp-dump.hpp"  // cpp_dump (debug)
#endif                            // ONLINE_JUDGE

#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <ios>      // std::ios_base
#include <iostream>
#include <tuple>

// ALIAS | STRUCT | CLASS | HELPER FUNCTIONS
namespace px {
using node = std::tuple<std::int64_t, std::int64_t>;  // NOTE: {high priority, low priority }
}  // namespace px

// PROBLEM KEYPOINTS
void solution() {
  int n;
  std::cin >> n;

  int odd = -1;
  int even = -1;
  std::int64_t sum = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    if (x % 2 == 0) even = x;
    if (x % 2 != 0) odd = x;

    sum += x;
  }

  if (sum % 2 == 0) {
    if (odd != -1 && even != -1)
      std::cout << "YES" << '\n';
    else
      std::cout << "NO" << '\n';
  } else {
    std::cout << "YES" << '\n';
  }
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
  std::cerr << "Empirical Run Time (SEC): " << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;

  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  std::cerr << "Empirical Memory Usage (MB): " << (usage.ru_maxrss / 1024.0) << std::endl;
#endif  // ONLINE_JUDGE
}
