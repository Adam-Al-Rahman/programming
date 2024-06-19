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
#include <functional>
#include <ios>  // std::ios_base
#include <iostream>
#include <vector>

// GLOBAL CONSTANTS EXPRESSIONS
constexpr std::int32_t MODULU = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t LARGE_NUM = std::int32_t(2e5) + 5;

// PROBLEM KEYPOINTS

// HELPER FUNCTIONS

// PROBLEM SOLUTION
void solution() {
  std::uint16_t n;
  std::cin >> n;

  std::uint16_t f;
  std::cin >> f;

  std::uint16_t k;
  std::cin >> k;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];

  f = f - 1;
  k = k - 1;
  int fav = a[f];

  std::vector<int> sorted_a = a;
  std::sort(sorted_a.begin(), sorted_a.end(), std::greater<int>());

  int sorted_kth = sorted_a[k];

  if (sorted_kth > fav) {
    std::cout << "NO" << '\n';
    return;
  }

  if ((k < n) && (sorted_kth <= fav) && (k + 1 >= n || sorted_a[k + 1] != fav)) {
    std::cout << "YES" << '\n';
    return;
  }

  std::cout << "MAYBE" << '\n';
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
