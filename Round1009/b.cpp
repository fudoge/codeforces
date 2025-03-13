#include <bits/stdc++.h>

#include <queue>
#define pii pair<int, int>
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    while (pq.size() > 1) {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();

        ll x = a + b - 1;
        pq.push(x);
    }

    cout << pq.top() << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
