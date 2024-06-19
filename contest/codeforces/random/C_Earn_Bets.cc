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
#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <cstdio>   // freopen
#include <ctime>    // std::clock
#include <ios>      // std::ios_base
#include <iostream>
#include <numeric>  // std::lcm and std::gcd
#include <vector>

// GLOBAL CONSTANTS EXPRESSIONS
constexpr std::int32_t MODULU = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t LARGE_NUM = std::int32_t(2e5) + 5;

// PROBLEM KEYPOINTS
// - i and j need not be equal

// HELPER FUNCTIONS
// Function to compute LCM of all elements in a vector
int find_lcm(const std::vector<std::uint16_t>& numbers) {
  return std::accumulate(numbers.begin(), numbers.end(), 1, [](int a, int b) { return std::lcm(a, b); });
}

// PROBLEM SOLUTION
void solution() {
  std::uint16_t n;
  std::cin >> n;

  std::vector<std::uint16_t> k(n);
  for (int i = 0; i < n; i++) std::cin >> k[i];

  int z = find_lcm(k);

  int sum = 0;
  for (std::uint16_t i = 0; i < n; i++) sum += (z / k[i]);

  if (sum < z) {
    for (int i = 0; i < n; i++) std::cout << (z / k[i]) << ' ';
    std::cout << '\n';
    return;
  }

  std::cout << -1 << '\n';
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
