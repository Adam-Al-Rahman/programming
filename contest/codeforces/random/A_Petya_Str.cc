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
#include <ctime>    // std::clock
#include <ios>      // std::ios_base
#include <iostream>

// GLOBAL CONSTANTS EXPRESSIONS
constexpr std::int32_t MODULU = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t LARGE_NUM = std::int32_t(2e5) + 5;

// PROBLEM KEYPOINTS

// HELPER FUNCTIONS

// PROBLEM SOLUTION
void solution() {
  std::string s1, s2;
  std::cin >> s1 >> s2;

  auto x = [](unsigned char c) { return std::tolower(c); };
  std::transform(s1.begin(), s1.end(), s1.begin(), x);
  std::transform(s2.begin(), s2.end(), s2.begin(), x);

  bool result = std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end());

  if (result)
    std::cout << -1 << '\n';
  else if (s1 == s2)
    std::cout << 0 << '\n';
  else
    std::cout << 1 << '\n';
}

/** optimal way
 * Instead use transform tolower it on the way each character
void solution() {
    std::string s1, s2;
    std::cin >> s1 >> s2;


    for (size_t i = 0; i < s1.size() && i < s2.size(); ++i) {
        char c1 = tolower(s1[i]);
        char c2 = tolower(s2[i]);
        if (c1 < c2) {
            std::cout << -1 << '\n';
            return;
        } else if (c1 > c2) {
            std::cout << 1 << '\n';
            return;
        }
    }

    if (s1.size() < s2.size()) {
        std::cout << -1 << '\n';
    } else if (s1.size() > s2.size()) {
        std::cout << 1 << '\n';
    } else {
        std::cout << 0 << '\n';
    }
}

*/

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
  // std::cin >> tests;  // overwrite
  while (tests--) solution();

#ifndef ONLINE_JUDGE
  std::clock_t end_time = std::clock();
  std::cerr << "Experimental Run Time(sec): " << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;
#endif  // ONLINE_JUDGE
}
