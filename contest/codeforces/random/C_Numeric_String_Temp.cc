// ╔════════════════════════════════════════════════════════════════════╗
// ║ Competitive programming is not about solving problems.             ║
// ║ It's about continuously evolving your approach to problem-solving. ║
// ╚════════════════════════════════════════════════════════════════════╝
// author: Adam-Al-Rahman <https://atiq-ur-rehaman.netlify.app>
// Q: https://codeforces.com/problemset/problem/2000/C

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
#include <unordered_map>
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
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  int m;
  std::cin >> m;

  while (m--) {
    std::string s;
    std::cin >> s;

    if (n != s.size()) {
      std::cout << "NO" << '\n';
      continue;
    }

    bool ok = false;
    std::unordered_map<char, int> char_to_int;
    std::unordered_map<int, char> int_to_char;

    for (int i = 0; i < n; ++i) {
      if (char_to_int.count(s[i]) == 0 && int_to_char.count(a[i]) == 0) {
        char_to_int[s[i]] = a[i];
        int_to_char[a[i]] = s[i];
      } else if (char_to_int[s[i]] != a[i] || int_to_char[a[i]] != s[i]) {
        std::cout << "NO" << '\n';
        ok = true;
        break;
      }
    }

    if (ok) continue;

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
  std::cerr << "Experimental Run Time (SEC): " << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;

  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  std::cerr << "Experimental Memory Usage (MB): " << (usage.ru_maxrss / 1024.0) << std::endl;
#endif  // ONLINE_JUDGE
}
