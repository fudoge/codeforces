#include <bits/stdc++.h>

using namespace std;

int res[] = {0, 1, 2, 6, 24, 120};
int fact(int n) {
  if (n >= 6)
    return 720;
  return res[n];
}

void solve() {
  vector<int> ans = {1};
  int n, d;
  cin >> n >> d;

  if (n >= 3 || d % 3 == 0)
    ans.push_back(3);
  if (d == 5)
    ans.push_back(5);
  if (n >= 3 || d == 7)
    ans.push_back(7);
  if (n >= 6 || (fact(n) * d) % 9 == 0)
    ans.push_back(9);

  for (const auto &num : ans) {
    cout << num << " ";
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
