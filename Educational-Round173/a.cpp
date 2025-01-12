#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dfs(ll n) {
  if (n <= 3)
    return 1;
  return 2 * dfs(n / 4);
}

void solve() {
  ll n;
  cin >> n;
  ll res = dfs(n);
  cout << res << "\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
