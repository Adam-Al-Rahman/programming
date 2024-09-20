// ╔════════════════════════════════════════════════════════════════════╗
// ║ Competitive programming is not about solving problems.             ║
// ║ It's about continuously evolving your approach to problem-solving. ║
// ╚════════════════════════════════════════════════════════════════════╝
// author: Adam-Al-Rahman <https://atiq-ur-rehaman.netlify.app>
// Q: https://codeforces.com/problemset/problem/2008/D

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
#include <string>
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

// int helper(int idx, int start, const std::vector<int>& p, const std::string& s, int count) {
//   if (idx == start) {  // proof: permutation cycyle: https://mathworld.wolfram.com/PermutationCycle.html
//     if (s[idx] == '0') count += 1;
//     return count;
//   }
//
//   // visited[idx] = true;
//   if (s[idx] == '0') count += 1;
//
//   return helper(p[idx], start, p, s, count);
// }

// PROBLEM SOLUTION
void solution() {
  int n;
  std::cin >> n;

  // Read permutation p
  std::vector<int> p(n, 0);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    p[i] = x - 1;  // Make p 0-indexed
  }

  std::string s;
  std::cin >> s;

  std::vector<int> zeros(n, 0);    // To store the size of zeros in each cycle
  std::vector<int> visited(n, 0);  // To track visited nodes

  // Process each element in the permutation
  for (int i = 0; i < n; ++i) {
    if (visited[i]) continue;  // If already processed, skip

    int count = 0;  // To count zeros in the current cycle
    // proof (permutation cycyle): https://mathworld.wolfram.com/PermutationCycle.html
    int start = i;  // Remember where the cycle started

    // Traverse the cycle until we visit all nodes in it
    while (!visited[i]) {
      visited[i] = 1;               // Mark node as visited
      if (s[i] == '0') count += 1;  // Count '0' in the cycle
      i = p[i];                     // Move to the next element in the cycle
    }

    // Assign the count of zeros to all elements in the current cycle
    while (visited[start] != 2) {
      zeros[start] = count;  // Assign the zero count to the current element
      visited[start] = 2;    // Mark as fully processed
      start = p[start];      // Move to the next element in the cycle
    }
  }

  for (int i = 0; i < n; ++i) std::cout << zeros[i] << ' ';
  std::cout << '\n';
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