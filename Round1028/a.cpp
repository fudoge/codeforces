#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    vector<pii> parr(4);
    for (int i = 0; i < 4; i++) {
        int x;
        cin >> x;
        parr[i] = {x, (i + 1) % 2};
    }

    sort(parr.begin(), parr.end());
    int firstLoser = parr[0].second;
    if (firstLoser == 0) {
        cout << "Gellyfish\n";
    } else {
        cout << "Flower\n";
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
