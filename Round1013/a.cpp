#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> freq(10, 0);
    freq[0] = 3;
    freq[1] = 1;
    freq[2] = 2;
    freq[3] = 1;
    freq[5] = 1;
    int remains = 8;

    vector<int> a(n);
    for (auto &i : a) cin >> i;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (freq[x] > 0) {
            freq[x]--;
            remains--;
            if (remains == 0) {
                cout << i + 1 << "\n";
                return;
            }
        }
    }
    cout << 0 << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
