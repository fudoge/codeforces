#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<bool> sieve(1e7 + 1, true);
vector<int> primes;

void solve() {
    int n;
    cin >> n;

    ll ans = 0;
    for (int a = 1; a < n; a++) {
        int lb =
            lower_bound(primes.begin(), primes.end(), n / a) - primes.begin();
        if (lb == primes.size() || primes[lb] * a > n) ans--;
        ans += lb + 1;
    }

    cout << ans << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    for (int i = 2; i <= 1e7; i++) {
        if (sieve[i] == false) continue;
        primes.emplace_back(i);
        for (int j = i * 2; j <= 1e7; j += i) {
            sieve[j] = false;
        }
    }

    while (t--) solve();
    return 0;
}
