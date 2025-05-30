#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve() {
    int n;
    cin >> n;
    vector<int> d(n + 1);
    vector<pii> obs(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        obs[i] = {l, r};
    }

    vector<pii> boundary(n + 1);
    boundary[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        int l = obs[i].first;
        int r = obs[i].second;

        int mov = d[i];

        if (mov == -1) {
            boundary[i].first = max(boundary[i - 1].first, l);
            boundary[i].second = min(boundary[i - 1].second + 1, r);
        } else {
            boundary[i].first = max(boundary[i - 1].first + mov, l);
            boundary[i].second = min(boundary[i - 1].second + mov, r);
        }

        if (boundary[i].first > boundary[i].second) {
            cout << "-1\n";
            return;
        }
    }

    int x = boundary.back().second;
    for (int i = n; i > 0; i--) {
        if (d[i] == -1) {
            if (x - 1 >= boundary[i - 1].first) {
                d[i] = 1;
            } else {
                d[i] = 0;
            }
        }
        x -= d[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    cout << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
