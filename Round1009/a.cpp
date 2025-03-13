#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

void solve() {
    int l, r, d, u;
    cin >> l >> r >> d >> u;

    if (l == r && r == d && d == u) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
