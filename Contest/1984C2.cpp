#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mod = 998244353;

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
ll inverse(int num) {
    if (num == 1) return 1;
    return (mod - ((mod / num) * inverse(mod % num)) % mod) % mod;
}

void solve() {
    int n; cin >> n;
    // -100 200 -10000
    vector<ll> pos_pref(n + 1), neg_pref(n + 1);
    vector<ll> a(n);
    // pos max, neg min
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        a[i] = x;
        pos_pref[i + 1] = max(llabs(pos_pref[i] + x), llabs(neg_pref[i] + x));
        neg_pref[i + 1] = min(neg_pref[i] + x, pos_pref[i] + x);
    }
    // for (auto i : pos_pref) cout << i << " "; cout << "\n";
    // for (auto i : neg_pref) cout << i << " "; cout << "\n";

    vector<pair<ll, ll>> dp(n + 1);
    dp[0] = {1, 1};
    for (int i = 1; i <= n; i++) {
        if (pos_pref[i - 1] == neg_pref[i - 1] && pos_pref[i] == neg_pref[i]) {
            dp[i] = dp[i - 1];
            (dp[i].first *= 2) %= mod;
            (dp[i].second *= 2) %= mod;
            continue;
        }

        if (pos_pref[i] == pos_pref[i - 1] + a[i - 1]) (dp[i].first += dp[i - 1].first) %= mod;
        if (pos_pref[i] == llabs(pos_pref[i - 1] + a[i - 1])) (dp[i].first += dp[i - 1].first) %= mod;
        if (pos_pref[i] == neg_pref[i - 1] + a[i - 1]) (dp[i].first += dp[i - 1].second) %= mod;
        if (pos_pref[i - 1] != neg_pref[i - 1] && pos_pref[i] == llabs(neg_pref[i - 1] + a[i - 1])) (dp[i].first += dp[i - 1].second) %= mod;

        if (neg_pref[i] == neg_pref[i - 1] + a[i - 1]) (dp[i].second += dp[i - 1].second) %= mod;
        if (neg_pref[i] == pos_pref[i - 1] + a[i - 1]) (dp[i].second += dp[i - 1].second) %= mod;
    }
    // for (auto [i, j] : dp) cout << i << " " << j << ", ";
    cout << dp[n].first << "\n";
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