#include <bits/stdc++.h>

#include <algorithm>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n);
    ll sumOfA = 0;

    for (auto &i : a) {
        cin >> i;
        sumOfA += i;
    }

    ll div = x / sumOfA;

    vector<int> c(n * 2);
    for (int i = 0; i < n * 2; i++) {
        c[i] = a[i % n];
    }

    int decrementedX = x - (div * sumOfA);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int lb = lower_bound(c.begin() + i, c.begin() + i + n, decrementedX) -
                 c.begin() - i;

        int d = 0;
        int inc;
        while ((inc = ((n * k) - (div * n + lb) + 1) - (d * n)) > 0) {
            ans += inc;
            d++;
        }
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
