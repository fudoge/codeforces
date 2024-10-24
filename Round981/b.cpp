#include <bits/stdc++.h>
#define ll long long

using namespace std;

int t;
int mat[501][501];

int scan(int r, int c, int n) {
  int res = INT_MAX;
  while (r < n && c < n) {
    res = min(res, mat[r][c]);
    r++;
    c++;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }

  // Iterate Each main Diag..
  ll ans = 0;
  int temp = scan(0, 0, n);
  if (temp < 0)
    ans += temp;
  for (int i = 1; i < n; ++i) {
    temp = scan(0, i, n);
    if (temp < 0)
      ans += temp;
    temp = scan(i, 0, n);
    if (temp < 0)
      ans += temp;
  }

  cout << -1 * ans << "\n";
}

int main(int argc, char *argv[]) {
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
