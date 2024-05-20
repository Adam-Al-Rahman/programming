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
#include <bitset>
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
//
int hamming_distance(std::string bin_str_first, std::string bin_str_second) {
  if (bin_str_first.size() != bin_str_second.size()) {
    std::cerr << "Error: Size of both binary string differs.";
    return -1;  // Indicate error
  }
  int distance = 0;

  for (int i = 0; i < bin_str_first.size(); i++) {
    if (bin_str_first[i] != bin_str_second[i]) distance++;
  }

  return distance;
}

// or
int hamming(int a, int b) { return __builtin_popcount(a ^ b); }

// PROBLEM SOLUTION
void solution() {
  int decimal = 7;
  std::bitset<32> binary_bits(decimal);

  std::string binary_bits_str = binary_bits.to_string();
  std::cout << '\n';
  std::cout << binary_bits_str << '\n';

  // For character string
  std::string str = "Hello";
  std::cout << "str: " << str << '\n';

  for (char c : str) {
    std::bitset<32> binary_bits(static_cast<int>(c));
    std::string binary_bits_str = binary_bits.to_string();
    std::cout << c << ": " << binary_bits_str << '\n';
  }
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
  // std::cin >> tests;  // overwrite
  while (tests--) solution();

#ifndef ONLINE_JUDGE
  std::clock_t end_time = std::clock();
  std::cerr << "Experimental Run Time(sec): " << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;
#endif  // ONLINE_JUDGE
}
