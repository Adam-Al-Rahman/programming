#include "bits/stdc++.h"

#define cout std::cout
std::mt19937 rnd(503);

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 5;

int n;
int a[N];
int p[N];

void solve() {
  cin >> n;
  int mex = 0;
  vector<bool> us(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] > 0) {
      p[i] = mex++;
      while (us[mex]) ++mex;
    } else {
      p[i] = mex - a[i];
    }
    us[p[i]] = 1;
  }
  for (int i = 0; i < n; ++i) {
    cout << p[i] << " ";
  }
}

void clean() {}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int _ = 1; _ <= t; ++_) {
    solve();
    clean();
    cout << "\n";
  }
}
