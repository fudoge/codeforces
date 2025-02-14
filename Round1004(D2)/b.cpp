#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  sort(arr.begin() + 1, arr.end());

  int left = 1;
  int right = 2;
  bool flag = true;
  while (right <= n) {
    if (arr[left] != arr[right]) {
      flag = false;
      break;
    }
    right++;

    while (right <= n && arr[right] == arr[left]) {
      arr[right]++;
      right++;
    }

    if (right > n) {
      int len = right - left;
      if (len % 2 == 1) {
        flag = false;
      }
      break;
    }

    left += 2;
    right = left + 1;
  }

  if (flag) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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
