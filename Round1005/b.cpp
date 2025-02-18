#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  template <typename T> size_t operator()(const T &x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(hash<T>{}(x) + FIXED_RANDOM);
  }

  template <typename T1, typename T2>
  size_t operator()(const pair<T1, T2> &p) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(operator()(p.first) ^ operator()(p.second) +
                                                FIXED_RANDOM);
  }

  template <typename... Args> size_t operator()(const tuple<Args...> &t) const {
    return apply(
        [this](const Args &...args) { return (operator()(args) ^ ...); }, t);
  }

  template <typename T> size_t operator()(const vector<T> &vec) const {
    size_t hash_value = 0;
    for (const T &elem : vec) {
      hash_value ^= operator()(elem) + 0x9e3779b9 + (hash_value << 6) +
                    (hash_value >> 2);
    }
    return hash_value;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  unordered_map<int, int, custom_hash> freq;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    freq[a[i]]++;
  }

  // 1개따리 서브어레이를 늘려라
  int ansL = 0, ansR = 0;
  int right = 1;
  for (int left = 1; left <= n; ++left) {
    if (freq[a[left]] != 1)
      continue;

    right = left;
    while (right <= n && freq[a[right]] == 1) {
      right++;
    }
    right--;

    if (ansR - ansL <= right - left) {
      ansR = right;
      ansL = left;
    }
    left = right;
  }

  if (n == 1) {
    ansL = 1;
    ansR = 1;
  }

  if (ansL == ansR && ansL == 0) {
    cout << "0\n";
  } else {
    cout << ansL << " " << ansR << "\n";
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
