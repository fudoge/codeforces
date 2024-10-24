#include <bits/stdc++.h>

using namespace std;

int arr[10001];
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> dp(n, vector<int>(2, 1e9));

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
