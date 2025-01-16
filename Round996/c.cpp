#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> mat(n, vector<ll>(m));
  string trace;
  cin >> trace;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  const int pivot = 0;
  int r = 0;
  int c = 0;
  for (const auto &mov : trace) {
    if (mov == 'D') {
      ll sum = 0;
      for (int j = 0; j < m; ++j) {
        sum += mat[r][j];
      }
      mat[r][c] = -sum;
      r++;
    } else {
      ll sum = 0;
      for (int i = 0; i < n; ++i) {
        sum += mat[i][c];
      }
      mat[r][c] = -sum;
      c++;
    }
  }
  ll sum = 0;
  for (int j = 0; j < m; ++j) {
    sum += mat[r][j];
  }
  mat[r][c] = -sum;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << mat[i][j] << " ";
    }
    cout << "\n";
  }
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
