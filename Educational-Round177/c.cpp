#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), d(n);
    for (auto &i : p) {
        cin >> i;
        i--;
    }

    for (auto &i : d) {
        cin >> i;
        i--;
    }

    int ruinedCount = 0;
    vector<bool> isRuined(n, false);
    for (int i = 0; i < n; i++) {
        int idx = d[i];
        if (isRuined[idx]) {
            cout << ruinedCount << " ";
        } else {
            ruinedCount++;
            isRuined[idx] = true;
            idx = p[idx];
            while (!isRuined[idx]) {
                isRuined[idx] = true;
                idx = p[idx];
                ruinedCount++;
            }
            cout << ruinedCount << " ";
        }
    }
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
