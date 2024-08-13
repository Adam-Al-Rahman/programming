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
#include <cstdlib>
#include <ctime>  // std::clock
#include <ios>    // std::ios_base
#include <iostream>
#include <limits>
#include <queue>
#include <tuple>  // std::tuple

// HEADERS (Current)
#include <functional>
#include <limits>
#include <vector>

// GLOBAL CONSTANTS EXPRESSIONS
namespace px {
constexpr std::int32_t mod = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t num = std::int32_t(2e5) + 5;
}  // namespace px

// PROBLEM KEYPOINTS
// if (weight == 0) the weight was erased.

// HELPER FUNCTIONS | STRUCT | CLASS | ALIAS
namespace px {
using node = std::tuple<std::int64_t, std::int64_t>;  //  NOTE: {high priority, low priority }
}  // namespace px

void dijkstra(int src, std::vector<std::vector<px::node>>& graph, std::vector<std::int64_t>& weights,
              std::vector<std::int64_t>& parent) {
  weights[src] = 0;

  std::vector<bool> visited(graph.size(), false);

  std::priority_queue<px::node, std::vector<px::node>, std::greater<>> nodes;
  nodes.push({0, src});  // {weight, src}

  while (!nodes.empty()) {
    auto [c_weight, current] = nodes.top();
    nodes.pop();

    if (visited[current]) continue;
    visited[current] = true;

    for (auto [n_weight, neighbor] : graph[current]) {
      std::int64_t new_weight = n_weight + c_weight;
      if (new_weight < weights[neighbor]) {
        weights[neighbor] = new_weight;
        parent[neighbor] = current;
        nodes.push({new_weight, neighbor});
      }
    }
  }
}

// PROBLEM SOLUTION
void solution() {
  int n, m, L, s, t;
  std::cin >> n >> m >> L >> s >> t;

  std::int64_t nx_zero = 0;
  std::vector<px::node> src_dest;
  std::vector<std::vector<px::node>> graph(n);
  for (int i = 0; i < n; i++) {
    std::int64_t src, dest, weight;
    std::cin >> src >> dest >> weight;

    if (weight == 0) nx_zero++;

    src_dest.push_back({src, dest});

    graph[src].push_back({weight, dest});
    graph[dest].push_back({weight, src});  // undirected
  }

  if (nx_zero == 0) {
    std::cout << "No" << '\n';
    return;
  }

  std::vector<std::int64_t> weights(n, std::numeric_limits<std::int64_t>::max());
  std::vector<std::int64_t> parent(n, -1);
  dijkstra(s, graph, weights, parent);  // In-Place operation

  if (weights[t] < L) {
    std::cout << "No" << '\n';
    return;
  }

  for (const auto& [src, dest] : src_dest) {
    std::int64_t weight = std::abs(weights[dest] - weights[src]);
    std::cout << src << ' ' << dest << ' ' << weight << '\n';
  }
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
