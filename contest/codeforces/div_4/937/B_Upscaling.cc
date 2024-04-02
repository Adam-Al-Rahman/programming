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
#include <cstdint>
#include <cstdio>  // freopen
#include <ctime>   // std::clock
#include <ios>     // std::ios_base
#include <iostream>

// GLOBAL CONSTANTS
constexpr std::int32_t MODULU = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t LARGE_NUM = 200005;

// PROBLEM KEYPOINTS

// HELPER FUNCTIONS

// PROBLEM SOLUTION
void solution() {
  std::uint16_t n;
  std::cin >> n;

  std::string hash_tag = "##";
  std::string dots = "..";

  bool choose_dots = false;

  std::string current_row;
  std::string row_chess;

  for (int i = 1; i <= n; i++) {
    if (choose_dots) {
      choose_dots = false;
      current_row += dots;
    } else {
      choose_dots = true;
      current_row += hash_tag;
    }
  }

  row_chess += current_row + '\n' + current_row + '\n';

  for (int i = 1; i < n; i++) {
    for (int i = 1; i < current_row.size(); i += 2) {
      if (current_row[i - 1] == '#' && current_row[i] == '#') {
        current_row[i - 1] = '.';
        current_row[i] = '.';
      } else if (current_row[i - 1] == '.' && current_row[i] == '.') {
        current_row[i - 1] = '#';
        current_row[i] = '#';
      }
    }

    row_chess += current_row + '\n' + current_row + '\n';
  }
  std::cout << row_chess;
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
  std::cin >> tests;  // overwrite
  while (tests--) solution();

#ifndef ONLINE_JUDGE
  std::clock_t end_time = std::clock();
  std::cerr << "Experimental Run Time(sec): "
            << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;
#endif  // ONLINE_JUDGE
}
