# Educational Codeforces Round177(Div. 2) Reivew(A~D)

[https://codeforces.com/contest/2086/problems/A](https://codeforces.com/contest/2086/problems/A)

I solved A, C in Contest, and Upsolved B, D with editorial.  
I spent too much time on B, stupidly.

## A - Cloudberry Jam
(math, greedy)
> It could be solved instantly with intuition, but I didn't.  
> Because I was not sure and afraid of WA.  
> For me, reducing penalties was important than solving fast.  
> So, I proved the equation.

### Approach
Basic formula was:
$$
x = \frac{\frac{2n \times 3}{4}}{3}
$$

So, It can be simple formula below:
$$
x = 2n
$$
while `x` is the amount of berries.

### Solution
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    ll n;
    cin >> n;
    cout << n * 2 << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```

## B - Large Array and Segments (Upsolved with Editorial)
(greedy, brute force, binary search, parametric search)
> I spent too much time in this problem.  
> But, I misunderstood the problem during the contest.  
> Instead, I was trying to count the number of the range `[l, r]` which sum is >= `x`.  
> Due to my physical and mental fatigue, my reading comprehension was off.  


### Approach
The array b is too big.
Naively solving will get TLE.
Instead we can simulate from the end of the array, summing backwards, and check when the suffix sum becomes `>= x`.
We want to maximize the minimum such that the suffix `[l, n*k] has a sum >= x`.  

1. If `sum of b` is smaller than `x`, print `0` and exit.
1. Initialize `l=1` and `r = n*k`.
2. While `l <= r`:
    - Initialize `mid=(l+r)/2`, which is the excluded length of prefixes.
    - Initialize `aCount`, which is the number of full `a` array.
    - Initialize `suff`, which is the remainder of the `mid - n*aCount`.
    - Calculate the subarray sum of range`[mid, n*k]`.
    - Subarray sum from position mid is: aCount * sum(a) + sum of last suff elements in a.  
    - If sum is smaller than `x`, set `r` to `mid-1`, to make the subarray larger.
    - Otherwise, set `l` to `mid+1`, to minimize the subarray.
4. Final answer is r. (maximum valid is `l`)

Also, It can be solved with `O(n)`, by finding the index of `l`

### Solution
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;

    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    if (accumulate(a.begin(), a.end(), 0LL) * k < x) {
        cout << "0\n";
        return;
    }

    ll l = 1, r = n * k;
    while (l <= r) {
        ll mid = (l + r) >> 1;

        ll aCount = (n * k - mid + 1) / n;
        ll suff = (n * k - mid + 1) % n;
        ll sum = aCount * accumulate(a.begin(), a.end(), 0LL);

        for (int i = n - suff; i < n; i++) {
            sum += a[i];
        }

        if (sum < x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << r << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```

## C - Disappearing Permutation 
(dfs, graph, dsu, greedy, implementation)
> Fortunately, I caught the idea with connected component of graph.

### Approach
A permutation can be viewed as a collection of disjoint cycles.  
Replacing elements with 0 breaks cycles.  
Each broken or incomplete cycle need some elements fixed to restore a permutation.

Treat the permutation p as a directed graph: i→p[i].
1. Build the permutation graph.
2. Track which element have been ruined:
3. For each query:
    - mark `d[i]` as ruined.
    - Start from that position, follow its cycle until reaching already ruined node.
    - Accumulate the number of the ruined positions.
    - Output the sum of the ruined positions.

### Solution
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), d(n);
    for (auto &i : p) {
        cin >> i;
        i--;
    }

    for (auto &i : d) {
        cin >> i;
        i--;
    }

    int ruinedCount = 0;
    vector<bool> isRuined(n, false);
    for (int i = 0; i < n; i++) {
        int idx = d[i];
        if (isRuined[idx]) {
            cout << ruinedCount << " ";
        } else {
            ruinedCount++;
            isRuined[idx] = true;
            idx = p[idx];
            while (!isRuined[idx]) {
                isRuined[idx] = true;
                idx = p[idx];
                ruinedCount++;
            }
            cout << ruinedCount << " ";
        }
    }
    cout << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```


## D - Even String (Upsolved with Editorial)
(dp, math, combinations, string)
> My first approach to consider `dp[s/2]` and 'All same characters should be in the same parity index' was correct.  
> But, I couldn't know how to considering its order.  
> And, Optimization like pow with divide and conquer to modular inverse was hard to think.

### Approach
Same characters must be in the same parity index.  
So, we divide the string into two subsequences:
- characters at odd indexes
- characters with even indexes
We don't care which index is odd or even, just that it must it must go entirely into one.

Let `dp[i]` be the number of ways to choose a subset of characters from c whose total frequecy sums to i.  
Because we want to choose a vaild group of letters to place in even positions, summing to s/2.  
Initialize `dp[0] = 1`, the base case(length zero)

Fill the dp table with napsack-like method:
- For each frequecy of the characters, perform like these:
```cpp
for (j = s; j >= 0; j--)
    if (j + c[i] <= s)
        dp[j + c[i]] += dp[j]
```

Permute characters within both groups:
$$
\text{Ways} = dp[s/2] \times s_{even}! \times s_{odd}!
$$

But we have repeated letters, we divide by the factorial of each letter count:
$$
\text{Divide by} \; \Pi^{26}_{i=1}c_i!
$$

Using a modular inverse of factorials to handle efficiently.

### Solution
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll MOD = 998244353;

ll bpow(ll x, ll p) {
    ll res = 1;
    while (p) {
        if (p % 2) {
            res = (res * x) % MOD;
        }
        p >>= 1;
        x = (x * x) % MOD;
    }

    return res;
}

ll fact(ll x) {
    ll res = 1;
    for (ll i = 1; i <= x; i++) {
        res = (res * i) % MOD;
    }

    return res;
}

void solve() {
    vector<ll> c(26);
    for (auto &i : c) cin >> i;
    ll s = accumulate(c.begin(), c.end(), 0LL);

    vector<ll> dp(s + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < 26; i++) {
        if (c[i] == 0) continue;

        for (int j = s; j >= 0; j--) {
            if (j + c[i] <= s) {
                dp[j + c[i]] = (dp[j + c[i]] + dp[j]) % MOD;
            }
        }
    }

    ll ans = dp[s / 2] * fact(s / 2) % MOD * fact((s + 1) / 2) % MOD;
    for (int i = 0; i < 26; i++) {
        ans = (ans * bpow(fact(c[i]), MOD - 2)) % MOD;
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
```

## Comment
After reading editoral for problem D,  
I started worrying about my limitation.  
I cannot think about the mathematical idea to optimize the problem.

I have to learn Mathematics for widely used for CP.  
But.. Stably solving A, B, C problems is priority for me.
