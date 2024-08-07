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

// HEADERS (Required)
#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <cstdio>   // freopen
#include <ctime>    // std::clock
#include <ios>      // std::ios_base
#include <iostream>

// HEADERS (Current)
#include <climits>
#include <functional>
#include <queue>  // std::priority_queue
#include <tuple>  // std::tuple
#include <vector>

// GLOBAL CONSTANTS EXPRESSIONS
namespace px {
constexpr std::int32_t mod = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t num = std::int32_t(2e5) + 5;
}  // namespace px

// PROBLEM KEYPOINTS

// HELPER FUNCTIONS | STRUCT | CLASS | ALIAS
namespace px {
using node = std::tuple<std::int64_t, std::int64_t, std::string>;  // NOTE: {weight, node, mode}
}

void dijkstra(std::int64_t src, const std::vector<std::vector<px::node>>& graph, std::vector<std::int64_t>& weights,
              std::vector<bool>& train_used) {
  weights[src] = 0;

  std::vector<bool> visited(graph.size(), false);

  std::priority_queue<px::node, std::vector<px::node>, std::greater<>> nodes;
  nodes.push({0, src, "bus"});  // Initial mode set to "bus"

  while (!nodes.empty()) {
    auto [c_weight, current, c_mode] = nodes.top();
    nodes.pop();

    if (visited[current]) continue;
    visited[current] = true;

    for (const auto& [n_weight, neighbor, n_mode] : graph[current]) {
      std::int64_t new_weight = c_weight + n_weight;
      if (new_weight < weights[neighbor] || (new_weight == weights[neighbor] && n_mode == "bus")) {
        weights[neighbor] = new_weight;
        train_used[neighbor] = (n_mode == "train");
        nodes.push({new_weight, neighbor, n_mode});
      }
    }
  }
}

void solution() {
  std::int64_t n, m, k;
  std::cin >> n >> m >> k;

  std::vector<std::vector<px::node>> graph(n + 1);  // start with index 1
  for (std::int64_t i = 0; i < m; ++i) {
    std::int64_t u, v, w;
    std::cin >> u >> v >> w;
    graph[u].emplace_back(w, v, "bus");
    graph[v].emplace_back(w, u, "bus");  // undirected graph
  }

  for (std::int64_t i = 0; i < k; ++i) {
    std::int64_t s, y;
    std::cin >> s >> y;
    graph[1].emplace_back(y, s, "train");
  }

  std::vector<std::int64_t> dist(n + 1, INT_MAX);
  std::vector<bool> train_used(n + 1, 0);
  dijkstra(1, graph, dist, train_used);  // src = 1

  std::int64_t ans = std::count(train_used.begin() + 1, train_used.end(), true);  // start with index 1

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
