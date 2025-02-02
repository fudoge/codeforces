#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  l--;
  r--;

  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  auto arr1 = arr;
  auto arr2 = arr1;

  int m = r - l + 1;
  sort(arr1.begin(), arr1.begin() + r + 1);
  sort(arr2.begin() + l, arr2.end());

  ll a = 0;
  for (int i = 0; i < m; ++i) {
    a += arr1[i];
  }

  ll b = 0;
  for (int i = l; i < m + l; ++i) {
    b += arr2[i];
  }

  cout << min(a, b) << "\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
