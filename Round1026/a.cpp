#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    sort(a.begin(), a.end());
    if ((a[n - 1] - a[0]) % 2 == 0) {
        cout << "0\n";
        return;
    }
    int l = 0;
    int r = n - 1;
    int stateL = a[l] % 2;
    int stateR = a[r] % 2;

    while (l < n && a[l] % 2 == stateL) l++;
    while (r >= 0 && a[r] % 2 == stateR) r--;

    int ans1 = l;
    int ans2 = n - r - 1;
    cout << min(ans1, ans2) << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
