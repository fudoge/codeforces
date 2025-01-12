#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  int minSum = 0;
  int maxSum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int l1 = 0, r1 = 0;
  int l2 = 2e9, r2 = -2e9;

  int prefixSum = 0;
  int mnl = 0, mxl = 0;
  int mnr = 2e9, mxr = -2e9;

  for (int i = 0; i < n; ++i) {
    prefixSum += arr[i];
    if (arr[i] != -1 && arr[i] != 1) {
      mnr = mnl;
      mxr = mxl;
      mnl = prefixSum;
      mxl = prefixSum;
    }
    l1 = min(l1, prefixSum - mxl);
    r1 = max(r1, prefixSum - mnl);
    l2 = min(l2, prefixSum - mxr);
    r2 = max(r2, prefixSum - mnr);
    mnl = min(mnl, prefixSum);
    mxl = max(mxl, prefixSum);
  }

  vector<int> res;
  if (l2 > r1) {
    for (int i = l1; i <= r1; ++i) {
      res.push_back(i);
    }
    for (int i = l2; i <= r2; ++i) {
      res.push_back(i);
    }
  } else if (r2 < l1) {
    for (int i = l2; i <= r2; ++i) {
      res.push_back(i);
    }
    for (int i = l1; i <= r1; ++i) {
      res.push_back(i);
    }
  } else {
    for (int i = min(l1, l2); i <= max(r1, r2); ++i) {
      res.push_back(i);
    }
  }

  cout << res.size() << "\n";
  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << " ";
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
