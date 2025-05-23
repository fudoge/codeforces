#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    int streakzero = 0;
    int sum = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (a[i] == 0) {
            streakzero++;
            if (streakzero >= 2) {
                flag = true;
                break;
            }
        } else {
            streakzero = 0;
        }
    }
    if (sum == n) flag = true;

    if (flag) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
