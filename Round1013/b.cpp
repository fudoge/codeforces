#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    sort(a.begin(), a.end());
    int ans = 0;
    int lb = lower_bound(a.begin(), a.end(), x) - a.begin();
    ans = n - lb;

    for (int i = lb - 1; i >= 0; i--) {
        int j = i;
        while (j > 0 && (i - j + 1) * a[j] < x) j--;
        if ((i - j + 1) * a[j] >= x) ans++;
        i = j;
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
