#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

int getMex(int lo, int hi) {
    if (hi == 1) {
        return 2;
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    vector<pii> ans;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 0) {
            if (i < a.size() - 1) {
                a[i] = getMex(0, a[i + 1]);
                ans.push_back({i + 1, i + 2});
                a.erase(a.begin() + i + 1);
            } else {
                a[i - 1] = getMex(0, a[i - 1]);
                ans.push_back({i, i + 1});
                a.pop_back();
            }
            i--;
        }
    }
    ans.push_back({1, a.size()});

    cout << ans.size() << "\n";
    for (const auto &[l, r] : ans) {
        cout << l << " " << r << "\n";
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
