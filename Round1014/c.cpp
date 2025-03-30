#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll oddCount = 0;
    ll ans = 0;
    for (auto &i : a) {
        cin >> i;
        ans += i;
        oddCount += (i & 1);
    }
    if (!oddCount || oddCount == n) {
        cout << *max_element(a.begin(), a.end()) << "\n";
    } else {
        cout << ans - oddCount + 1 << "\n";
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
