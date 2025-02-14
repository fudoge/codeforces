#include <bits/stdc++.h>

using namespace std;

void solve() {
  int x, y;
  cin >> x >> y;

  int ans = x + 1 - y;
  if (ans >= 0 && ans % 9 == 0) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
