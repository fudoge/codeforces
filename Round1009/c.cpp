#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

void solve() {
    ll x;
    cin >> x;

    if (x < 5 || ((x + 1) & x) == 0) {
        cout << "-1\n";
        return;
    }

    ll ms = log2(x);
    ll ls = log2(x ^ (x & (x - 1)));

    ll y = ((1LL << (ms + 1)) - 1) ^ x;
    y |= 1LL << ls;

    if ((min({x, y, x ^ y}) ^ max({x, y, x ^ y})) + min({x, y, x ^ y}) ==
        max({x, y, x ^ y})) {
        cout << "-1\n";
        return;
    }
    cout << y << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
