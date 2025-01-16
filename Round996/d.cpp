#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k, l;
  cin >> n >> k >> l;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  double K = k;
  double L = l;

  double T = a[0];
  double last_pt = 0;
  double S = 0;

  for (int i = 1; i < n; ++i) {
    double this_pt =
        min(L, min(a[i] + T, max(last_pt + K, (a[i] - T + last_pt + K) / 2.0)));
    T += max(0.0, this_pt - last_pt - K);
    S += min(K, this_pt - last_pt);
    last_pt = this_pt;
  }

  S += min(K, L - last_pt);
  cout << (int)round(2 * (L - S + a[0])) << "\n";
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
