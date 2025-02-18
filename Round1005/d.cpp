#include <bits/stdc++.h>
#define LIMIT 2 * (int)1e5
using namespace std;

const int W = 30;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n), pre(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i == 0) {
      pre[i] = a[i];
    } else {
      pre[i] = pre[i - 1] ^ a[i];
    }
  }

  vector<vector<int>> last(n, vector<int>(W));
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      last[i] = last[i - 1];
    }
    last[i][(int)log2(a[i])] = i;

    for (int j = W - 2; j >= 0; --j) {
      last[i][j] = max(last[i][j], last[i][j + 1]);
    }
  }

  while (q--) {
    int x;
    cin >> x;

    int idx = n - 1;
    while (idx >= 0 && x > 0) {
      int msb = (int)log2(x);
      int nxt = last[idx][msb];

      x ^= pre[idx] ^ pre[nxt];
      idx = nxt;

      if (nxt == -1 || a[nxt] > x)
        break;

      x ^= a[nxt];
      idx--;
    }

    cout << n - idx - 1 << " ";
  }

  cout << "\n";
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
