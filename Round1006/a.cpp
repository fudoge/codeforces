#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

void solve() {
  int n, k, p;
  cin >> n >> k >> p;

  if (k < 0)
    k = -k;

  int res = k / p;
  res += k % p == 0 ? 0 : 1;

  if (res > n) {
    cout << "-1\n";
  } else {
    cout << res << "\n";
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
