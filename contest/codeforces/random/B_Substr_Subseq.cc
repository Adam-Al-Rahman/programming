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
#include <string>

// GLOBAL CONSTANTS EXPRESSIONS
constexpr std::int32_t MODULU = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t LARGE_NUM = std::int32_t(2e5) + 5;

// PROBLEM KEYPOINTS

// HELPER FUNCTIONS

// PROBLEM SOLUTION
void solution() {
  std::string a;
  std::cin >> a;

  std::string b;
  std::cin >> b;

  std::string s = a;

  char x = b[0];
  int i = 0;
  int j = 0;

  for (int it = 0; it < a.size(); it++) {
    if (a[i] == x) {
      i = it;
      break;
    } else {
      i = it;
    }
  }

  if (a[i] != x && (i == (a.size() - 1))) {
    std::cout << (a.size() + b.size()) << '\n';
    return;
  } else if (a[i] == x && (i == (a.size() - 1))) {
    std::cout << (a.size() + b.size()) - 1 << '\n';
    return;
  }

  while (j < b.size()) {
    if (a[i] != x) {
      a.push_back(x);
      i++;
    }
  }

  std::cout << s.size() << '\n';
}

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
  std::cerr << "Experimental Run Time(sec): " << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;
#endif  // ONLINE_JUDGE
}
