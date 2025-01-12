#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void solve() {
  ll l, r, g;
  cin >> l >> r >> g;

  ll L = l + (l % g == 0 ? 0 : g - (l % g));
  ll R = r - r % g;
  for (int i = 0; i <= (R - L) / g; ++i) {
    for (int j = 0; j <= i; j++) {
      if (gcd(L + j * g, R - (i - j) * g) == g) {
        cout << L + j * g << " " << R - (i - j) * g << "\n";
        return;
      }
    }
  }

  cout << "-1 -1\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
