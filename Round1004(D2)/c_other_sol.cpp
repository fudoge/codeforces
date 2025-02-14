#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adds = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999};

bool contains_seven(ll x) {
  while (x > 0) {
    if (x % 10 == 7)
      return true;
    x /= 10;
  }
  return false;
}

void solve() {
  ll n;
  cin >> n;

  if (contains_seven(n)) {
    cout << "0\n";
    return;
  }

  int ans = 7;
  for (int i = 0; i < 8; ++i) {
    ll x = n;
    for (int j = 0; j < 6; ++j) {
      x += adds[i];
      if (contains_seven(x)) {
        ans = min(ans, j + 1);
        break;
      }
    }
  }

  cout << ans << "\n";
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
}
