#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

bool check(int mid, int n, int m, ll k) {
    ll benches_in_a_row = 1LL * mid * (m / (mid + 1)) + m % (mid + 1);
    return benches_in_a_row * n >= k;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int lo = 1, hi = m;
    int ans = m;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid, n, m, k)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
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
