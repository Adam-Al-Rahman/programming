// problem: https://codeforces.com/contest/2043/problem/0

// HEADERS [Required]
#include <unordered_map>
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

std::int64_t coins(std::int64_t n, std::unordered_map<std::int64_t, std::int64_t>& cache) {
  if (n <= 3) return 1;

  if (cache.find(n) != cache.end()) return cache[n];

  std::int64_t count = coins(n / 4, cache);
  count += coins(n / 4, cache);

  return cache[n] = count;
}
}  // namespace px

// PROBLEM KEYPOINTS
void solution() {
  std::int64_t n;
  std::cin >> n;

  std::unordered_map<std::int64_t, std::int64_t> cache;
  std::cout << px::coins(n, cache) << '\n';
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
