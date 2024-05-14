#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int> 
#define endl "\n"
#define int long long
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using pbds_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int llinf = 4e18;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

struct nCr {
    int mod;
    nCr(int mod) : mod(mod) {};
    int inverse(int num) {
        if (num == 1) return 1;
        return (mod - ((mod / num) * inverse(mod % num)) % mod) % mod;
    }
    int fast_exp(int x, int p) {
        int ans = 1;
        while (p > 0) {
            if (p & 1) ans = (ans * x) % mod;
            x = x * x % mod;
            p >>= 1;
        }
        return ans;
    }
    vector<int> fac;
    void BuildLucas(int n) {
        fac.resize(n + 1);
        fac[0] = 1;
        for(int i = 1; i <= n; i++) {
            fac[i] = fac[i - 1] * i % mod;
        }
    }
    int C(int m, int n) {
        return m < n ? 0 : fac[m] * inverse(fac[n]) % mod * inverse(fac[m - n]) % mod;
    }
    int Lucas(int m, int n) {
        return n == 0 ? 1 % mod : Lucas(m / mod, n / mod) * C(m % mod, n % mod) % mod;
    }
};

void solve() {
    nCr ncr(1e9 + 7);
    ncr.BuildLucas(3e5);
    vector<int> dp(3e5 + 1);
    dp[0] = 1;
    dp[1] = 1; dp[2] = 3;
    for (int i = 3; i <= 3e5; i++) {
        dp[i] = (dp[i - 1] + (dp[i - 2] * (i * 2 - 2)) % mod) % mod;
    }
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int l = n;
        for (int i = 0; i < k; i++) {
            int x, y; cin >> x >> y;
            if (x == y) {
                l--;
            }
            else l -= 2;
        }
        cout << dp[l] % mod << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
}