#include <bits/stdc++.h>

#include <queue>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll MOD = 998244353;

vector<ll> powof2(100001);

void solve() {
    ll n;
    cin >> n;
    vector<ll> p(n), q(n), r(n);
    for (auto &i : p) cin >> i;
    for (auto &i : q) cin >> i;

    priority_queue<pll, vector<pll>, less<>> pMaxHeap;
    priority_queue<pll, vector<pll>, less<>> qMaxHeap;

    for (int i = 0; i < n; i++) {
        pMaxHeap.emplace(p[i], i);
        qMaxHeap.emplace(q[i], i);

        ll pwiseFirst = pMaxHeap.top().second;
        ll pwiseSecond = i - pwiseFirst;

        ll qwiseFirst = qMaxHeap.top().second;
        ll qwiseSecond = i - qwiseFirst;

        if (p[pwiseFirst] > q[qwiseFirst] ||
            (p[pwiseFirst] == q[qwiseFirst] &&
             q[pwiseSecond] >= p[qwiseSecond])) {
            r[i] = (powof2[p[pwiseFirst]] + powof2[q[pwiseSecond]]) % MOD;
        } else {
            r[i] = (powof2[q[qwiseFirst]] + powof2[p[qwiseSecond]]) % MOD;
        }
    }

    for (const auto &elem : r) {
        cout << elem << " ";
    }
    cout << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    powof2[0] = 1;
    for (int i = 1; i < 100001; i++) {
        powof2[i] = (powof2[i - 1] * 2) % MOD;
    }
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
