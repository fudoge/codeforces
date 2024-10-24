#include <bits/stdc++.h>

using namespace std;

int getMinimumSwap(int i, vector<int> &indices) {}

void solve() {
  int n, temp;
  cin >> n;
  vector<int> indices(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    indices[temp] = i;
  }

  int ans = getMinimumSwap(0, indices);
}

int main(int argc, char *argv[]) {
  int t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
