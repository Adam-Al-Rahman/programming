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
#include <map>
#include <utility>
#include <vector>

// GLOBAL CONSTANTS EXPRESSIONS
constexpr std::int32_t MODULU = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t LARGE_NUM = std::int32_t(2e5) + 5;

// PROBLEM KEYPOINTS

// HELPER FUNCTIONS | STRUCT | CLASS

// PROBLEM SOLUTION
void solution() {
  std::int64_t n, m;
  std::cin >> n >> m;

  std::vector<std::int64_t> a(n);
  std::map<std::int64_t, std::int64_t> mp;

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    mp[a[i]]++;
  }

  std::int64_t ans = 0;
  for (auto &[k, p] : mp) {  // p numbers of flowers with k petals
    // find if there are any flowers with k+1 petals
    auto it = mp.find(k + 1);
    auto p1 = (it != mp.end() ? it->second : 0);

    // Calculate the max possible combination of k and k+1
    for (std::int64_t x = 0; x <= p && x * k <= m; x++) {  // `x * k > m` break the loop
      auto y = std::min((m - x * k) / (k + 1), p1);
      ans = std::max(ans, x * k + y * (k + 1));
    }
  }

  std::cout << ans << '\n';
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
