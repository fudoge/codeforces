#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i <= 9; ++i) {
    string s = to_string(n - i);
    int md = 0;
    for (char ch : s) {
      if (ch <= '7') {
        md = max(md, ch - '0');
      }
    }
    if (i >= 7 - md) {
      cout << i << "\n";
      return;
    }
  }
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
