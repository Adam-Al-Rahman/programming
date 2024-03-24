/*

  Competitive programming is not about solving problems; it's about continuously
  evolving your approach to problem-solving.

*/

/**
In online judge like [codeforces, codechef]
`ONLINE_JUDGE` is pre-define. so use ifndef to check it.
*/

// ALIASES [RECOMMENDED NOT TO USE]
#define ll long long int

// HEADERS
#include <cstdint>
#include <cstdio>  // freopen
#include <ctime>   // std::clock
#include <ios>     // std::ios_base
#include <iostream>

// GLOBAL CONSTANTS
constexpr std::int32_t MODULU = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t LARGE_NUM = 200005;

// HELPER FUNCTIONS

// PROBLEM SOLUTION
void solution() {}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);  // tie() is a method that simply guarantees the flushing of
                    // std::cout before std::cin accepts an input. For
                    // INTERACTIVE PROBLEM
  std::cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("./test_zero/input.txt", "r", stdin);
  freopen("./test_zero/output.txt", "w", stdout);
#endif  // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  std::clock_t start_time = std::clock();
#endif  // ONLINE_JUDGE

  std::uint32_t tests = 1;
  std::cin >> tests;  // overwrite
  while (tests--) solution();

#ifndef ONLINE_JUDGE
  std::clock_t end_time = std::clock();
  std::cerr << "Experimental Run Time(sec): "
            << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;
#endif  // ONLINE_JUDGE
}
