#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;

ll solution(vector<ll> &nums, int n) {
  stack<pair<ll, int>> s;

  for (int i = 0; i < n; ++i) {
    ll sum = nums[i];
    ll cnt = 1;

    while (s.size() > 0 && s.top().first >= sum / cnt) {
      sum += s.top().first * s.top().second;
      cnt += s.top().second;
      s.pop();
    }

    s.push({sum / cnt, cnt - sum % cnt});
    if (sum % cnt != 0) {
      s.push({sum / cnt + 1, sum % cnt});
    }
  }

  ll maxVal = s.top().first;
  while (s.size() > 1) {
    s.pop();
  }

  return maxVal - s.top().first;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    cin >> n;
    vector<ll> nums(n);

    for (int j = 0; j < n; ++j) {
      cin >> nums[j];
    }
    cout << solution(nums, n) << "\n";
  }
  return 0;
}
