#include <bits/stdc++.h>

using namespace std;

void solve() {
  int l, r;
  cin >> l >> r;

  int ans = 0;
  if (l == 1 && r == 1) {
    cout << "1\n";
  } else {
    cout << r - l << "\n";
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
