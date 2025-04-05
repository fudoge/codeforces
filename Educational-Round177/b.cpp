#include <bits/stdc++.h>

#include <numeric>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;

    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    if (accumulate(a.begin(), a.end(), 0ll) * k < x) {
        cout << "0\n";
        return;
    }

    ll l = 1, r = n * k;
    while (l <= r) {
        ll mid = (l + r) >> 1;

        ll aCount = (n * k - mid + 1) / n;
        ll suff = (n * k - mid + 1) % n;
        ll sum = aCount * accumulate(a.begin(), a.end(), 0ll);

        for (int i = n - suff; i < n; i++) {
            sum += a[i];
        }

        if (sum < x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << r << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
