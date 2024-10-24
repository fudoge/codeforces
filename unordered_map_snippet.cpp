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

int main() {
  unordered_map<int, int, custom_hash> int_map;
  unordered_map<pair<int, int>, int, custom_hash> pair_map;
  unordered_map<tuple<int, int, int>, int, custom_hash> tuple_map;
  unordered_map<vector<int>, int, custom_hash> vector_map;

  int_map[1] = 10;
  pair_map[{1, 2}] = 20;
  tuple_map[{1, 2, 3}] = 30;
  vector_map[{1, 2, 3}] = 40;

  cout << "int_map[1]: " << int_map[1] << endl;
  cout << "pair_map[{1, 2}]: " << pair_map[{1, 2}] << endl;
  cout << "tuple_map[{1, 2, 3}]: " << tuple_map[{1, 2, 3}] << endl;
  cout << "vector_map[{1, 2, 3}]: " << vector_map[{1, 2, 3}] << endl;

  return 0;
}
