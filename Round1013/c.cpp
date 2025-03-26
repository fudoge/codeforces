#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    } else if (n % 2 == 0) {
        cout << "-1\n";
        return;
    }
    vector<int> a(n), freq(n + 1, 0);
    int offset = n - 3;
    for (int i = 0; i < n; i++) {
        int idx = (offset + i) % n;
        a[idx] = (i + idx) % n;
    }

    for (const auto &x : a) cout << x + 1 << " ";
    cout << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
