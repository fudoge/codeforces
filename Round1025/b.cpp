#include <bits/stdc++.h>

#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<pll> boundaries = {{a, m}, {n, b}, {n - a + 1, m}, {n, m - b + 1}};

    ll ans = LLONG_MAX;
    for (auto [h, w] : boundaries) {
        ll res = 0;
        while (h > 1) {
            res++;
            h = (h + 1) / 2;
        }

        while (w > 1) {
            res++;
            w = (w + 1) / 2;
        }

        ans = min(ans, res);
    }
    cout << ans + 1 << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
