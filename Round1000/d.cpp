#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f(int x, int ka, vector<ll> &aSum, vector<ll> &bSum) {
  return aSum[ka] + bSum[x - ka];
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector<ll> aSum(n + 1);
  vector<ll> bSum(m + 1);
  for (int i = 1; i <= n; ++i) {
    aSum[i] = aSum[i - 1] + a[n - i] - a[i - 1];
  }
  for (int i = 1; i <= m; ++i) {
    bSum[i] = bSum[i - 1] + b[m - i] - b[i - 1];
  }

  vector<ll> ans;

  for (int x = 1; 2 * x - m <= n - x; ++x) {
    ll l = max(0, 2 * x - m);
    ll r = min(x, n - x);

    if (l > r)
      break;

    while (r - l > 3) {
      ll ml = (l * 2 + r) / 3, mr = (l + r * 2) / 3;
      if (f(x, ml, aSum, bSum) > f(x, mr, aSum, bSum))
        r = mr;
      else
        l = ml;
    }

    ll mans = 0;
    for (int i = l; i <= r; ++i) {
      mans = max(mans, f(x, i, aSum, bSum));
    }
    ans.push_back(mans);
  }

  int kMax = ans.size();
  cout << kMax << "\n";
  for (const auto &elem : ans)
    cout << elem << " ";
  cout << "\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
