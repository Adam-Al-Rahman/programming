// problem: https://codeforces.com/contest/2051/problem/B

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
  int n, a, b, c;
  std::cin >> n >> a >> b >> c;

  std::int64_t ab = a + b;
  std::int64_t abc = a + b + c;

  int count = 0;

  if (n >= abc) {
    int abc_rem = n % abc;
    int abc_q = n / abc;
    n -= (abc_q * abc);
    count += (abc_q * 3);
  }

  int turn = 0;

  while (n > 0) {
    if (turn == 0) {
      n -= a;
      count += 1;
      turn = 1;
    }

    if (n > 0 && turn == 1) {
      n -= b;
      count += 1;
      turn = 2;
    }

    if (n > 0 && turn == 2) {
      n -= c;
      count += 1;
      turn = 0;
    }
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
  std::cerr << "Empirical Run Time (SEC): " << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;

  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  std::cerr << "Empirical Memory Usage (MB): " << (usage.ru_maxrss / 1024.0) << std::endl;
#endif  // ONLINE_JUDGE
}
