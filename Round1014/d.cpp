#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pic = pair<int, char>;

string base = "LIT";

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (count(s.begin(), s.end(), s[0]) == n) {
        cout << "-1\n";
        return;
    }

    vector<int> ans;

    while (true) {
        vector<pic> cnt;
        for (auto i : base) {
            cnt.emplace_back(count(s.begin(), s.end(), i), i);
        }
        sort(cnt.begin(), cnt.end());

        if (cnt[0].first == cnt[1].first && cnt[1].first == cnt[2].first) break;

        auto op = [&](int i) -> void {
            string z = base;
            z.erase(find(z.begin(), z.end(), s[i]));
            z.erase(find(z.begin(), z.end(), s[i + 1]));
            ans.push_back(i);
            s = s.substr(0, i + 1) + z[0] + s.substr(i + 1);
        };

        bool done = false;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) continue;
            if (s[i] != cnt[0].second && s[i + 1] != cnt[0].second) {
                op(i);
                done = true;
                break;
            }
        }
        if (done) continue;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) continue;
            if (s[i] == cnt[2].second) {
                op(i);
                op(i + 1);
                op(i);
                op(i + 2);
                done = true;
                break;
            } else if (s[i + 1] == cnt[2].second) {
                op(i);
                op(i);
                op(i + 1);
                op(i + 3);
                done = true;
                break;
            }
        }
    }

    cout << ans.size() << "\n";
    for (const auto &elem : ans) {
        cout << elem + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
