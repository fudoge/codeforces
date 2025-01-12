#include <bits/stdc++.h>
#define ll long long

using namespace std;

int fact[] = {0, 1, 2, 6, 24, 120, 720, 5040};

void solve() {
  int n, d;
  cin >> n >> d;
  n = min(n, 7);

  int nf = fact[n];
  string num = string(nf, '0' + d);

  vector<int> ans = {1};

  int sum_digits = d * nf;
  if (sum_digits % 3 == 0)
    ans.push_back(3);

  if (d == 5)
    ans.push_back(5);

  ll temp = 0;
  for (int i = 0; i < nf; ++i) {
    temp = (temp * 10 + 1) % 7;
  }
  if ((temp * d) % 7 == 0)
    ans.push_back(7);

  if (sum_digits % 9 == 0)
    ans.push_back(9);

  for (const auto &i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
