/*
╔═══════════════════════════════════════════════╗
║                                               ║
║  Competitive programming is not about solving ║
║  problems; it's about continuously evolving   ║
║  your approach to problem-solving.            ║
║                                               ║
╚═══════════════════════════════════════════════╝

q: https://codeforces.com/problemset/problem/295/B
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
#include <vector>

// GLOBAL CONSTANTS EXPRESSIONS
constexpr std::int32_t MODULU = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t INF = std::int32_t(2e5) + 5;

// PROBLEM KEYPOINTS

// HELPER FUNCTIONS

// PROBLEM SOLUTION
void solution() {
  std::uint32_t n;
  std::cin >> n;

  std::vector<std::vector<std::int64_t>> dist(n, std::vector<std::int64_t>(n, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) std::cin >> dist[i][j];

  std::vector<int> x(n);
  for (int i = 0; i < n; i++) std::cin >> x[i];

  std::reverse(x.begin(), x.end());

  std::vector<std::int64_t> ans;

  for (int k = 0; k < n; k++) {
    int k_v = x[k] - 1;  // to make it zero index;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::int64_t new_dist = dist[i][k_v] + dist[k_v][j];
        dist[i][j] = std::min(dist[i][j], new_dist);
      }
    }

    std::int64_t sum = 0;
    for (int i = 0; i <= k; i++) {
      for (int j = 0; j <= k; j++) {
        sum += dist[x[i] - 1][x[j] - 1];  // to make zero index
      }
    }

    ans.push_back(sum);
  }

  std::reverse(ans.begin(), ans.end());

  for (auto elem : ans) std::cout << elem << ' ';
  std::cout << '\n';
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
