#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(false)
#define lson cur << 1
#define rson cur << 1 | 1
#define mid ((l + r) >> 1)
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define lowbit(x) (x & (-x))
const int maxn = 1e6 + 10;
const int mod = 998244353;
using namespace std;
mt19937 rnd(time(NULL));

struct edge {
  int u, v;
  ll w;
} e[maxn];

int n, m, l, s, t;
vector<array<int, 2>> g[maxn];

bool vis[maxn];

ll dis[maxn][2];
ll dif = 0;

void dij(int op) {
  for (int i = 0; i <= n; ++i) {
    vis[i] = 0;
    dis[i][op] = 1e18;
  }
  dis[s][op] = 0;
  priority_queue<pll, vector<pll>, greater<>> q;
  q.push({0, s});
  while (q.size()) {
    auto [dist, u] = q.top();
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto [v, id] : g[u]) {
      ll w = e[id].w;
      if (op == 1) {
        if (w == 0 && dis[u][1] < dis[v][0] + dif) {
          w = dis[v][0] + dif - dis[u][1];
          e[id].w = w;
        }
      }
      w = max(1ll, w);
      if (dis[v][op] > dis[u][op] + w) {
        dis[v][op] = dis[u][op] + w;
        q.push({dis[v][op], v});
      }
    }
  }
}
void solve() {
  cin >> n >> m >> l >> s >> t;
  for (int i = 1; i <= m; ++i) {
    cin >> e[i].u >> e[i].v >> e[i].w;
    g[e[i].u].pb({e[i].v, i});
    g[e[i].v].pb({e[i].u, i});
  }
  dij(0);
  if (dis[t][0] > l) {
    cout << "NO\n";
    return;
  }
  dif = l - dis[t][0];

  dij(1);
  if (dis[t][1] != l) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (int i = 1; i <= m; ++i) {
    if (e[i].w == 0) {
      e[i].w = 1;
    }
    cout << e[i].u << " " << e[i].v << " " << e[i].w << "\n";
  }
}

int main() {
  IOS;
  cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
