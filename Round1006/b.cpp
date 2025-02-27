#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

void solve() {
  int n;
  string s;
  cin >> n;
  cin >> s;

  int dashCount = 0;
  int underScoreCount = 0;

  for (char ch : s) {
    if (ch == '-') {
      dashCount++;
    } else {
      underScoreCount++;
    }
  }

  if (dashCount < 2 || underScoreCount < 1) {
    cout << "0\n";
    return;
  }

  ll a = dashCount / 2 + (dashCount & 1);
  ll b = dashCount / 2;

  cout << a * b * underScoreCount << "\n";
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
