#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

ll fast_exp(ll x, ll p) {
    x %= mod;
    ll ans = 1;
    while (p > 0) {
        if (p & 1) ans = (ans * x) % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return ans;
}

// 之間有幾個 *k 不會進位
void solve() {
    // 1~100, 3: 1, 2, 3, 10, 11, 12, 13, 20, 21, 22, 23, 30, 31, 32, 33
    // 4 ^ 2 - 1
    // 1~100, 7: 1, 10, 11
    // 2 ^ 2 - 1
    // 9 / k + 1
    ll l, r, k; cin >> l >> r >> k;
    cout << (fast_exp(9 / k + 1, r) - fast_exp(9 / k + 1, l) + mod) % mod << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}