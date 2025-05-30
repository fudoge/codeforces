#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    string s;
    cin >> s;

    stack<char> stk;
    bool flag = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stk.emplace('(');
        } else {
            stk.pop();
            if (i != s.size() - 1 && stk.empty()) {
                flag = true;
            }
        }
    }
    if (!flag) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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
