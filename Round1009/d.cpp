#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pll> circles(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        circles[i].first = x;
    }
    for (int i = 0; i < n; i++) {
        ll r;
        cin >> r;
        circles[i].second = r;
    }

    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll l = circles[i].first - circles[i].second;
        ll r = circles[i].first + circles[i].second;

        for (ll j = l; j <= r; j++) {
            mp[j] = max(
                mp[j], 1 + 2 * (ll)(sqrt(circles[i].second * circles[i].second -
                                         (j - circles[i].first) *
                                             (j - circles[i].first))));
        }
    }
    ll ans = 0;
    for (const auto& elem : mp) {
        ans += elem.second;
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
