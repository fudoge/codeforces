#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;

  if (n == 1) {
    cout << x << "\n";
    return;
  }

  int orSUM = 0;
  int num = 0;
  bool flag = true;
  for (int i = 0; i < n - 1; i++) {
    if (flag) {
      if (num > x || (((orSUM | num) & ~(x)) > 0)) {
        flag = false;
        num = 0;
      }
    }
    cout << num << " ";
    orSUM |= num;
    if (flag)
      num++;
  }
  if ((orSUM | num) == x) {
    cout << num << " ";
  } else {
    cout << x << " ";
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
