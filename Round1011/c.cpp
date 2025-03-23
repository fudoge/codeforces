#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

void solve() {
    ll x, y;
    cin >> x >> y;

    if (x == y) {
        cout << "-1\n";
        return;
    }

    ll k = 1LL << 32;
    cout << k - max(x, y) << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
