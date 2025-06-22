#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> b(n);
    for (auto &i : b) cin >> i;

    vector<array<int, 3>> queries(q);
    for (int i = q - 1; i >= 0; i--) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        z--;
        queries[i] = {x, y, z};
    }
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
