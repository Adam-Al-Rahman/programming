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

// HEADERS
#include <algorithm>
#include <cstdint>
#include <cstdio>  // freopen
#include <ctime>   // std::clock
#include <ios>     // std::ios_base
#include <iostream>
#include <vector>

// GLOBAL CONSTANTS
constexpr std::int32_t MODULU = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t LARGE_NUM = 200005;

// PROBLEM KEYPOINTS
// -----------------
// * Valera reads each book up to the end, that is, he doesn't start reading the
// book if he doesn't have enough free time to finish reading it. (current_sum >
// time then continue)
// * i, then book number i + 1, then book number i + 2 and so on (continuous sub
// array)
// * the maximum number of books Valera can read.
// Try: Kadane's Algorithm (greedy approach) [**failed]
// Try: Two pointers

// HELPER FUNCTIONS

// PROBLEM SOLUTION
void solution() {
  std::uint32_t num_books;
  std::cin >> num_books;

  std::uint32_t time;
  std::cin >> time;

  std::vector<std::uint16_t> a(num_books);
  for (std::int32_t i = 0; i < num_books; i++) {
    std::cin >> a[i];
  }

  std::uint32_t time_sum = 0;
  std::uint32_t max_counts = 0;

  for (std::int32_t i = 0; i < num_books; i++) {
    std::uint32_t current_count = 0;
    for (std::int32_t j = i; j < num_books; j++) {
      time_sum += a[j];
      if (time_sum > time) {
        break_loop = true;
        break;
      }

      current_count++;

      if (time_sum == time) {
        break_loop = true;
        break;
      }
    }
    time_sum = 0;
    max_counts = std::max(current_count, max_counts);
  }

  std::cout << max_counts << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("./test_zero/input.txt", "r", stdin);
  freopen("./test_zero/output.txt", "w", stdout);
#endif  // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  std::clock_t start_time = std::clock();
#endif  // ONLINE_JUDGE

  std::uint32_t tests = 1;
  // std::cin >> tests;  // overwrite
  while (tests--) solution();

#ifndef ONLINE_JUDGE
  std::clock_t end_time = std::clock();
  std::cerr << "Experimental Run Time(sec): "
            << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;
#endif  // ONLINE_JUDGE
}
