#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int inf = 4e18;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> c(n), v(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> v[i];
        mx += v[i];
    }
    vector dp(n + 1, vector<int>(mx + 1, inf));
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= mx; j++) {
            if (j - v[i - 1] < 0) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                if (dp[i - 1][j] > dp[i - 1][j - v[i - 1]] + c[i - 1] && dp[i - 1][j - v[i - 1]] + c[i - 1] <= k * (i - 1)) {
                    dp[i][j] = dp[i - 1][j - v[i - 1]] + c[i - 1];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    for (int i = mx; i >= 0; i--) {
        if (dp[n][i] <= k * (n - 1)) {
            cout << i << '\n';
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}