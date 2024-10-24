#include <bits/stdc++.h>
#define ll long long
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
  int ans = 0;

  ll sum = 0;
  int last = -2;
  unordered_map<ll, int, custom_hash> mp;
  mp[0] = -1;

  int temp;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    sum += temp;
    if (mp[sum] != 0 && mp[sum] >= last) {
      ans++;
      last = i + 1;
    }
    mp[sum] = i + 1;
  }
  cout << ans << "\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
