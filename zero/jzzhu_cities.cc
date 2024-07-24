/*
╔═══════════════════════════════════════════════╗
║  Competitive programming is not about solving ║
║  problems; it's about continuously evolving   ║
║  your approach to problem-solving.            ║
╚═══════════════════════════════════════════════╝

author: Adam-Al-Rahman <https://atiq-ur-rehaman.netlify.app>
*/

// ONLINE_JUDGE
// #define ONLINE_JUDGE

// HEADERS
#include <climits>
#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <cstdio>   // freopen
#include <ctime>    // std::clock
#include <functional>
#include <ios>  // std::ios_base
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

// GLOBAL CONSTANTS EXPRESSIONS
constexpr std::int32_t MODULU = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t LARGE_NUM = std::int32_t(2e5) + 5;

// PROBLEM KEYPOINTS

// HELPER FUNCTIONS | STRUCT | CLASS
using Edge = std::tuple<std::int64_t, std::int64_t, std::string>;  // NOTE: {weight, node, mode}

void dijkstra(std::int64_t src, const std::vector<std::vector<Edge>>& graph, std::vector<std::int64_t>& dist,
              std::vector<int>& used) {
  dist[src] = 0;
  std::vector<bool> visited(graph.size(), false);
  std::priority_queue<Edge, std::vector<Edge>, std::greater<>> pq;
  pq.push({0, src, "bus"});  // Initial mode set to "bus"

  while (!pq.empty()) {
    auto [current_weight, current, mode] = pq.top();
    pq.pop();

    if (visited[current]) continue;
    visited[current] = true;

    for (const auto& [weight, dest, edge_mode] : graph[current]) {
      std::int64_t new_weight = current_weight + weight;
      if (new_weight < dist[dest] || (new_weight == dist[dest] && edge_mode == "bus")) {
        dist[dest] = new_weight;
        used[dest] = (edge_mode == "train");
        pq.push({new_weight, dest, edge_mode});
      }
    }
  }
}

void solution() {
  std::int64_t n, m, k;
  std::cin >> n >> m >> k;

  std::vector<std::vector<Edge>> graph(n + 1);  // start with 1
  for (std::int64_t i = 0; i < m; ++i) {
    std::int64_t u, v, w;
    std::cin >> u >> v >> w;
    graph[u].emplace_back(w, v, "bus");
    graph[v].emplace_back(w, u, "bus");
  }

  for (std::int64_t i = 0; i < k; ++i) {
    std::int64_t s, y;
    std::cin >> s >> y;
    graph[1].emplace_back(y, s, "train");
  }

  std::vector<std::int64_t> dist(n + 1, INT_MAX);
  std::vector<int> used(n + 1, 0);
  dijkstra(1, graph, dist, used);

  std::int64_t ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += used[i];
  }

  std::cout << k - ans << '\n';
}

// ENTRY: MAIN
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
