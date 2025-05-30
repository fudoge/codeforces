#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;

bool check(int k, vector<int>& b, vector<vector<pii>>& adj) {
    vector<int> dp(n + 1, INT_MIN);
    dp[1] = 0;

    for (int i = 1; i <= n; i++) {
        if (i > 1 && dp[i] <= 0) {
            continue;
        }
        dp[i] += b[i];
        dp[i] = min(dp[i], k);
        for (const auto& [nextNode, nextWeight] : adj[i]) {
            if (nextWeight <= dp[i]) {
                dp[nextNode] = max(dp[nextNode], dp[i]);
            }
        }
    }

    return dp[n] > 0;
}

void solve() {
    cin >> n >> m;
    int maxW = 0;
    vector<int> b(n + 1);
    vector<vector<pii>> adj(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        maxW = max(maxW, w);

        adj[s].emplace_back(t, w);
    }

    int lo = 1, hi = maxW;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;

        if (check(mid, b, adj)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
