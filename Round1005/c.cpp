#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<ll> pref(n), suff(n);

  if (a[0] > 0)
    pref[0] = a[0];
  for (int i = 1; i < n; ++i) {
    pref[i] = pref[i - 1];
    if (a[i] > 0) {
      pref[i] += a[i];
    }
  }

  if (a[n - 1] < 0) {
    suff[n - 1] = -a[n - 1];
  }
  for (int i = n - 2; i >= 0; --i) {
    suff[i] = suff[i + 1];
    if (a[i] < 0) {
      suff[i] -= a[i];
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, pref[i] + suff[i]);
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
