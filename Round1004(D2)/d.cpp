#include <bits/stdc++.h>
#include <numeric>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> x(n + 1), isx(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    isx[x[i]] = 1;
  }

  // if permutation
  if (accumulate(isx.begin(), isx.end(), 0) == n) {
    int i1 = 0, in = 0;
    for (int i = 1; i <= n; ++i) {
      if (x[i] == 1)
        i1 = i;
      if (x[i] == n)
        in = i;
    }
    cout << "? " << i1 << " " << in << endl;
    int ans;
    cin >> ans;
    if (ans < n - 1) {
      cout << "! A" << endl;
    } else if (ans > n - 1) {
      cout << "! B" << endl;
    } else {
      cout << "? " << in << " " << i1 << endl;
      cin >> ans;
      if (ans == n - 1) {
        cout << "! B" << endl;
      } else {
        cout << "! A" << endl;
      }
    }
  } else {
    for (int i = 1; i <= n; ++i) {
      if (!isx[i]) {
        cout << "? " << i << " " << 1 + (i == 1 ? 1 : 0) << endl;
        int ans;
        cin >> ans;
        if (ans == 0) {
          cout << "! A" << endl;
        } else {
          cout << "! B" << endl;
        }
        return;
      }
    }
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
