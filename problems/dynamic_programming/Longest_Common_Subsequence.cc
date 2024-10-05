// ╔════════════════════════════════════════════════════════════════════╗
// ║ Competitive programming is not about solving problems.             ║
// ║ It's about continuously evolving your approach to problem-solving. ║
// ╚════════════════════════════════════════════════════════════════════╝
// author: Adam-Al-Rahman <https://atiq-urrehaman.netlify.app>

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

// ALIAS | STRUCT | CLASS | HELPER FUNCTIONS
namespace px {
using float32_t = float;                              // 32-bit floating-point type
using float64_t = double;                             // 64-bit floating-point type
using node = std::tuple<std::int64_t, std::int64_t>;  // NOTE: {high priority, low priority }
}  // namespace px

std::string helper(int i, int j, const std::string& s1, const std::string& s2,
                   std::vector<std::vector<std::string>>& cache) {
  // Base Case
  if (i == s1.size() || j == s2.size()) return "";

  // Cache check
  if (cache[i][j] != "-") return cache[i][j];

  // Transition: If characters match
  if (s1[i] == s2[j]) {
    // NOTE: Include s1[i] before `helper` to return
    return s1[i] + helper(i + 1, j + 1, s1, s2, cache);
  }

  // Transition: If characters didn't match
  std::string option1 = helper(i + 1, j, s1, s2, cache);
  std::string option2 = helper(i, j + 1, s1, s2, cache);

  return cache[i][j] = (option1.size() > option2.size() ? option1 : option2);
}

// PROBLEM SOLUTION
void solution() {
  std::string s1;
  std::cin >> s1;

  std::string s2;
  std::cin >> s2;

  std::string lcs = "";
  std::vector<std::vector<std::string>> cache(s1.size(), std::vector<std::string>(s2.size(), "-"));

  std::cout << helper(0, 0, s1, s2, cache) << '\n';
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
