#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll MOD = 998244353;

ll bpow(ll x, ll p) {
    ll res = 1;
    while (p) {
        if (p % 2) {
            res = (res * x) % MOD;
        }
        p >>= 1;
        x = (x * x) % MOD;
    }

    return res;
}

ll fact(ll x) {
    ll res = 1;
    for (ll i = 1; i <= x; i++) {
        res = (res * i) % MOD;
    }

    return res;
}

void solve() {
    vector<ll> c(26);
    for (auto &i : c) cin >> i;
    ll s = accumulate(c.begin(), c.end(), 0LL);

    vector<ll> dp(s + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < 26; i++) {
        if (c[i] == 0) continue;

        for (int j = s; j >= 0; j--) {
            if (j + c[i] <= s) {
                dp[j + c[i]] = (dp[j + c[i]] + dp[j]) % MOD;
            }
        }
    }

    ll ans = dp[s / 2] * fact(s / 2) % MOD * fact((s + 1) / 2) % MOD;
    for (int i = 0; i < 26; i++) {
        ans = (ans * bpow(fact(c[i]), MOD - 2)) % MOD;
    }
    cout << ans << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
