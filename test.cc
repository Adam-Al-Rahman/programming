#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define Gondozu                \
  ios::sync_with_stdio(false); \
  cout.tie(NULL);              \
  cin.tie(NULL);

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vector<int>>;

const int OO = 1e9 + 5;
const int N = 2e5 + 5;

void TC() {
  int n, k;
  cin >> n >> k;
  int a[n * 2];
  vi pos[n + 1];
  for (int i = 0; i < n * 2; ++i) {
    cin >> a[i];
    pos[a[i]].pb(i);
  }

  vector<int> l, r;
  for (int i = 1; i <= n; ++i) {
    if (pos[i].front() < n && pos[i].back() < n && l.size() < 2 * k) {
      l.pb(i), l.pb(i);
    } else if (pos[i].front() >= n && pos[i].back() >= n && r.size() < 2 * k)
      r.pb(i), r.pb(i);
  }

  for (int i = 1; i <= n; ++i) {
    if ((pos[i].front() < n && pos[i].back() < n) ||
        (pos[i].front() >= n && pos[i].back() >= n))
      continue;
    if (l.size() < 2 * k) l.pb(i), r.pb(i);
  }

  for (int i : l) cout << i << ' ';
  cout << '\n';
  for (int i : r) cout << i << ' ';
}

int32_t main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
  Gondozu int t = 1;
  cin >> t;
  while (t--) {
    TC();
    cout << '\n';
  }
  return 0;
}
