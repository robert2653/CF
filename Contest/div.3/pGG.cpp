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
using pbds_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using pbds_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct edge {
    int from; int to;
    int weight;
};
struct info {
    int mn;
    int be_painted;
    info(){
        mn = be_painted = inf;
    }
};
const int llinf = 4e18;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = max(pre[i], min(n, i + v[i]));
    }
    
    vector<int> dp(n + 1, n);
    for (int i = 0, x = 0; ; i = pre[i + 1], x++) {
        dp[i] = x;
        if (i == n) {
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j - v[j] + 1 <= i) {
                int cur = j + 1;
                int mx = 0;
                for (int k = i; k < j; k++) {
                    mx = max(mx, min(n, k + v[k]));
                }
                for (int k = j + 1, x = dp[i] + 1; ; k = mx, x++) {
                    while (cur <= k && cur < n) {
                        mx = max(mx, min(n, cur + v[cur]));
                        cur++;
                    }
                    dp[k] = min(dp[k], x);
                    if (mx <= k) {
                        break;
                    }
                }
            }
        }
    }
    
    cout << dp[n] << "\n";
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
    while(t--){
        solve();
    }
}