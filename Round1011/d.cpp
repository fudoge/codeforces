#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    priority_queue<int> pq;

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int d;
        cin >> d;
        pq.push(d);

        if ((n - i + 1) % (k + 1) == 0) {
            ans += pq.top();
            pq.pop();
        }
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
