#include <bits/stdc++.h>

#include <algorithm>
#define pii pair<int, int>
#define ll long long
using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    if (n == 1) {
        cout << "NO\n";
        return;
    }

    for (int i = n - 1; k > 0 && i >= 0; i--) {
        int largestIdx = i;
        char largest = s[i];
        for (int j = 0; j < i; j++) {
            if (s[j] > largest) {
                largest = s[j];
                largestIdx = j;
            }
        }
        if (largestIdx != i) {
            swap(s[i], s[largestIdx]);
            k--;
        }
    }

    string r = s;
    reverse(r.begin(), r.end());

    if (s < r) {
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
