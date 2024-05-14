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
const int mod = 998244353;
const int maxn = 2e5 + 5;

struct nCr {
    int mod;
    nCr(int mod) : mod(mod) { };
    int inverse(int num) {
        if (num == 1) return 1;
        return (mod - ((mod / num) * inverse(mod % num)) % mod) % mod;
    }
    int fast_exp (int x, int p){
        int ans = 1;
        while  (p > 0) {
            if (p & 1) ans = (ans * x) % mod;
            x = x * x % mod;
            p >>= 1;
        }
        return ans;
    }
    vector<int> fac, inv_fac;
    void Build_Fac(int n) {
        fac.resize(n + 1);
        inv_fac[0] = fac[0] = 1;
        for(int i = 1; i <= n; i++){
            fac[i] = fac[i - 1] * i % mod;
            inv_fac[i] = inverse(fac[i]);
        }
    }
    int C(int m, int n){
        return m < n ? 0 : fac[m] * inverse(fac[n]) % mod * inverse(fac[m - n]) % mod;
    }
    int Lucas(int m, int n){
        return n == 0 ? 1 % mod : Lucas(m / mod, n / mod) * C(m % mod, n % mod) % mod;
    }
};
void solve(){
    nCr ncr(mod);
    int n, q; cin >> n >> q;
    vector<int> g(n + 1), pref_g(n + 1), s(n + 1), pref_s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
        pref_g[i] = pref_g[i - 1] + g[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        pref_s[i] = pref_s[i - 1] + s[i];
    }
    ncr.Build_Fac(max(pref_s[n]));
    int up = 1;
    int down = 1;
    for (int i = 0; i < n; i++) {

    }

}
signed main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}