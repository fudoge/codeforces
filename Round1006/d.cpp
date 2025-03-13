#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int L, R;
    int minProfit = 0;
    for (int l = 1; l <= n; ++l) {
        int smallerCount = 0;
        int largerCount = 0;
        for (int r = l; r <= n; r++) {
            if (arr[l] < arr[r]) {
                largerCount++;
            } else if (arr[l] > arr[r]) {
                smallerCount++;
            }
            int profit = largerCount - smallerCount;
            if (profit < minProfit) {
                L = l;
                R = r;
                minProfit = profit;
            }
        }
    }

    if (minProfit == 0) {
        cout << "1 1\n";
    } else {
        cout << L << " " << R << "\n";
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
