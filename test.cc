/**
 *    Copyright tourist 2024
 *    created: 15.03.2024 10:39:06
 **/

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool fail = false;
    int p = 0;
    for (int x : a) {
      if (x >= 10 && x / 10 >= p && x % 10 >= x / 10) {
        p = x % 10;
      } else {
        if (x >= p) {
          p = x;
        } else {
          fail = true;
          break;
        }
      }
    }
    cout << (fail ? "NO" : "YES") << '\n';
  }
  return 0;
}
