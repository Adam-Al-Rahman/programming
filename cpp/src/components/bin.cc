#include <iostream>
using namespace std;

int main() {
  int n, m;

  cin >> n >> m;

  int num[n], num2[m];

  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }

  for (int j = 0; j < m; j++) {
    cin >> num2[j];
  }

  for (int k = 0; k < m; k++) {
    cout << num[k] << " " << num2[k];
  }
}
