/*
╔═══════════════════════════════════════════════╗
║                                               ║
║  Competitive programming is not about solving ║
║  problems; it's about continuously evolving   ║
║  your approach to problem-solving.            ║
║                                               ║
╚═══════════════════════════════════════════════╝

author: Adam-Al-Rahman <https://atiq-ur-rehaman.netlify.app>
*/

// ONLINE_JUDGE
// #define ONLINE_JUDGE

// HEADERS
#include <algorithm>
#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <cstdio>   // freopen
#include <cstdlib>
#include <ctime>  // std::clock
#include <ios>    // std::ios_base
#include <iostream>
#include <unordered_map>
#include <vector>

// GLOBAL CONSTANTS EXPRESSIONS
constexpr std::int32_t MODULU = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t LARGE_NUM = std::int32_t(2e5) + 5;

// PROBLEM KEYPOINTS

// HELPER FUNCTIONS

// PROBLEM SOLUTION
void solution() {
  int x1, x2, x3;
  std::cin >> x1 >> x2 >> x3;

  std::unordered_map<int, int> num_count;
  num_count[x1]++;
  num_count[x2]++;
  num_count[x3]++;

  std::vector<int> nx = {x1, x2, x3};
  std::sort(nx.begin(), nx.end());

  int normal = nx[1];

  int ans = 0;
  if (num_count[x1] > 1)
    ans = std::abs(x1 - x2) + std::abs(x1 - x3);
  else if (num_count[x2] > 1)
    ans = std::abs(x2 - x1) + std::abs(x2 - x3);
  else if (num_count[x3] > 1)
    ans = std::abs(x1 - x3) + std::abs(x2 - x3);
  else {
    ans = std::abs(normal - x1) + std::abs(normal - x2) + std::abs(normal - x3);
  }

  std::cout << ans << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("./zero/input.txt", "r", stdin);
  freopen("./zero/output.txt", "w", stdout);
#endif  // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  std::clock_t start_time = std::clock();
#endif  // ONLINE_JUDGE

  std::uint32_t tests = 1;
  std::cin >> tests;  // overwrite
  while (tests--) solution();

#ifndef ONLINE_JUDGE
  std::clock_t end_time = std::clock();
  std::cerr << "Experimental Run Time(sec): " << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;
#endif  // ONLINE_JUDGE
}
