#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool isPrime(int x) {
    if (x < 2) return false;
    int rootX = sqrt(x);
    for (int i = 2; i <= rootX + 1; i++) {
        if (x % i == 0) return false;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    int globalGCD = a[0];
    for (int i = 1; i < n; i++) {
        globalGCD = gcd(a[i], globalGCD);
    }

    bool flag = false;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == globalGCD) {
            flag = true;
            cnt++;
        }
        a[i] /= globalGCD;
    }

    if (flag) {
        cout << n - cnt << "\n";
        return;
    }

    vector<int> divs(5001, 0);
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int j = 2; j <= x; j++) {
            if (!isPrime(j)) continue;
            if (x % j == 0) divs[j]++;
        }
    }

    int minelem = INT_MAX;
    for (int i = 2; i <= 5000; i++) {
        if (divs[i] == 0) continue;
        minelem = min(minelem, divs[i]);
    }

    cout << minelem + n - 1 << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
