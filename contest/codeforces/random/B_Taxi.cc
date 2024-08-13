// ╔════════════════════════════════════════════════════════════════════╗
// ║ Competitive programming is not about solving problems.             ║
// ║ It's about continuously evolving your approach to problem-solving. ║
// ╚════════════════════════════════════════════════════════════════════╝
// author: Adam-Al-Rahman <https://atiq-ur-rehaman.netlify.app>

// ONLINE_JUDGE
// #define ONLINE_JUDGE

// HEADERS (Required)
#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <cstdio>   // freopen
#include <ctime>    // std::clock
#include <ios>      // std::ios_base
#include <iostream>
#include <tuple>  // std::tuple

// HEADERS (Current)
#include <vector>

// GLOBAL CONSTANTS EXPRESSIONS
namespace px {
constexpr std::int32_t mod = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t num = std::int32_t(2e5) + 5;
}  // namespace px

// PROBLEM KEYPOINTS

// HELPER FUNCTIONS | STRUCT | CLASS | ALIAS
namespace px {
using node = std::tuple<std::int64_t, std::int64_t>;  // NOTE: {high priority, low priority }
}  // namespace px

// PROBLEM SOLUTION
void solution() {
  int n;
  std::cin >> n;

  std::vector<int> si_count(4 + 1, 0);  // +1: 1-indexing
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    si_count[x]++;
  }

  int min_taxi = si_count[4];  // Taxis for groups of 4

  // Pair groups of 3 with groups of 1
  int three_one = std::min(si_count[3], si_count[1]);
  min_taxi += three_one;
  si_count[3] -= three_one;
  si_count[1] -= three_one;

  // Remaining groups of 3 will each need their own taxi
  min_taxi += si_count[3];
  si_count[3] = 0;

  // Pair groups of 2 with each other
  min_taxi += si_count[2] / 2;
  if (si_count[2] % 2 == 1) {
    // One remaining group of 2 needs to be paired with up to two groups of 1
    si_count[1] = std::max(si_count[1] - 2, 0);
    min_taxi++;
  }

  // Remaining groups of 1 will be grouped into taxis of up to 4
  min_taxi += (si_count[1] + 3) / 4;  // +3: round up the division result of si_count[1] / 4

  std::cout << min_taxi << '\n';
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
  // std::cin >> tests;  // overwrite
  while (tests--) solution();

#ifndef ONLINE_JUDGE
  std::clock_t end_time = std::clock();
  std::cerr << "Experimental Run Time(sec): " << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;
#endif  // ONLINE_JUDGE
}
