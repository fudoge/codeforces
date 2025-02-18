#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int i = 0;
  while (i < n && s[i] == '0') {
    i++;
  }

  bool flag = false;
  int ans = 0;

  while (i < n && s[i] == '1') {
    flag = true;
    i++;
  }
  if (flag)
    ans++;

  while (i < n) {
    flag = false;
    while (i < n && s[i] == '0') {
      flag = true;
      i++;
    }
    if (flag)
      ans++;

    flag = false;
    while (i < n && s[i] == '1') {
      flag = true;
      i++;
    }
    if (flag)
      ans++;
  }

  cout << ans << "\n";
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
