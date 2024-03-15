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
struct edge {
    int from; int to;
    int weight;
};
struct node {
    int sum;
};
const int llinf = 4e18;
const int inf = 2e9;
const int mod = 998244353;
const int maxn = 2e5 + 5;
struct nCr {
    int mod;
    nCr(int mod) : mod(mod){ };
    int inverse(int num){
        if(num == 1) return 1;
        return (mod - ((mod / num) * inverse(mod % num)) % mod) % mod;
    }
    int fast_exp(int x, int p){
        int ans = 1;
        while(p > 0){
            if(p & 1) ans = (ans * x) % mod;
            x = x * x % mod;
            p >>= 1;
        }
        return ans;
    }
    vector<int> fac;
    void BuildLucas(int n){
        fac.resize(n + 1);
        fac[0] = 1;
        for(int i = 1; i <= n; i++){
            fac[i] = fac[i - 1] * i % mod;
        }
    }
    int C(int m, int n){
        return m < n ? 0 : fac[m] * inverse(fac[n]) % mod * inverse(fac[m - n]) % mod;
    }
    int Lucas(int m, int n){
        return n == 0 ? 1 % mod : Lucas(m / mod, n / mod) * C(m % mod, n % mod) % mod;
    }
};
void solve(nCr &ncr){
    int type1, type2, type3, type4;
    cin >> type1 >> type2 >> type3 >> type4;
    if(type1 == 0 && type2 == 0 && type3 == 0 && type4 == 0){
        cout << 1 << "\n";
    }
    else if(type1 == type2){
        int ans1 = ncr.Lucas(type1 + type3 - 1, type3) * ncr.Lucas(type1 + type4, type4) % mod;
        int ans2 = ncr.Lucas(type1 + type3, type3) * ncr.Lucas(type1 + type4 - 1, type4) % mod;
        cout << (ans1 + ans2) % mod << "\n";
    }
    else if(abs(type1 - type2) <= 1){
        int k = max(type1, type2);
        cout << ncr.Lucas(k + type3 - 1, type3) * ncr.Lucas(k + type4 - 1, type4) % mod << "\n";
    }
    else cout << 0 << "\n";
}
signed main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    nCr ncr(mod);
    ncr.BuildLucas(2e6);
    while(t--){
        solve(ncr);
    }
}