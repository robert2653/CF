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
struct node {
    int sum;
};
const int llinf = 4e18;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
void solve(){
    int n; cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    vector<pair<int, int>> dp(n + 2, pair<int, int>(inf, inf));
    dp[0] = dp[n + 1] = {0, 0};
    for(int i = 1; i <= n; i++){
        // 往後 paint
        for(int j = 1; j <= n; j++){
            if(dp[j - 1].first == inf) continue;
            pair<int, int> mn(dp[j - 1].first, j);
            for(int k = j; k <= min(n, j + v[j] - 1); k++){
                if(dp[k].second == j) continue;
                if(dp[k].first < mn.first){
                    mn.first = dp[k].first;
                    mn.second = k;
                }
                if(dp[k].first > mn.first + 1){
                    dp[k] = mn;
                    dp[k].first++;
                    dp[k].second = j;
                }
            }
        }
        // 往前 paint
        for(int j = max(0LL, i - v[i]); j < i; j++){
            if(dp[j].first + 1 < dp[i].first){
                dp[i].first = dp[j].first + 1;
                dp[i].second = i;
            }
        }
    }
    cout << dp[n].first << endl;
    for(int i = 0; i <= n + 1; i++){
        printf("i: %lld, first: %lld, second: %lld\n", i, dp[i].first, dp[i].second);
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
    cin >> t;
    while(t--){
        solve();
    }
}