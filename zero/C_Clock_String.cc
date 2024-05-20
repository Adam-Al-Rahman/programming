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
#include <cstdint>
#include <cstdio>  // freopen
#include <ctime>   // std::clock
#include <ios>     // std::ios_base
#include <iostream>

// GLOBAL CONSTANTS EXPRESSIONS
constexpr std::int32_t MODULU = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t LARGE_NUM = std::int32_t(2e5) + 5;

// PROBLEM KEYPOINTS

// HELPER FUNCTIONS

// PROBLEM SOLUTION
void solution() {
  std::int16_t a, b, c, d;
  std::cin >> a >> b >> c >> d;

  if ((a >= std::min(c, d) && a <= std::max(c, d)) && (b >= std::min(c, d) && b <= std::max(c, d)))
    std::cout << "NO" << '\n';
  else
    std::cout << "YES" << '\n';
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
