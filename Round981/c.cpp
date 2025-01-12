#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  for (int i = 1; i < n / 2; ++i) {
    if (arr[i - 1] == arr[i] || arr[n - i - 1] == arr[n - i]) {
      swap(arr[i], arr[n - i - 1]);
    }
  }

  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (arr[i - 1] == arr[i])
      ans++;
  }
  cout << ans << "\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
