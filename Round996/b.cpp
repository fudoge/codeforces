#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int temp;
  int minimum_lack = 0;
  int minimum_satisfied = INT_MAX;
  int lack_count = 0;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    a[i] -= temp;
    if (a[i] >= 0) {
      minimum_satisfied = min(minimum_satisfied, a[i]);
    } else {
      lack_count++;
      minimum_lack = min(minimum_lack, a[i]);
    }
  }

  if (lack_count >= 2 || abs(minimum_lack) > minimum_satisfied)
    cout << "NO\n";
  else
    cout << "YES\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
