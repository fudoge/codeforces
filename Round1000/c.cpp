#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  vector<int> degree(n, 0);

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    degree[u]++;
    degree[v]++;
  }

  if (n == 2) {
    cout << "0\n";
    return;
  }

  int ans = 1;
  int mans = 0;
  auto sdeg = degree;
  sort(sdeg.begin(), sdeg.end());
  for (int i = 0; i < n; ++i) {
    ans = degree[i];
    vector<int> ideg;
    for (int v : adj[i]) {
      ideg.emplace_back(degree[v]);
    }
    ideg.emplace_back(degree[i]);
    sort(ideg.begin(), ideg.end(), greater<>());

    vector<int> rem;
    int mx = -1;
    for (int d : ideg) {
      if (sdeg.back() == d) {
        sdeg.pop_back();
        rem.emplace_back(d);
      }
    }
    reverse(rem.begin(), rem.end());

    if (!sdeg.empty()) {
      mx = max(mx, sdeg.back());
    }
    for (int v : adj[i]) {
      mx = max(mx, degree[v] - 1);
    }
    for (int d : rem) {
      sdeg.emplace_back(d);
    }
    mans = max(ans + mx - 1, mans);
  }
  cout << mans << "\n";
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
