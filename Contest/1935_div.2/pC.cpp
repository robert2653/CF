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
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
void solve(){
    int n; cin >> n;
    int k; cin >> k;
    int ans = 0;
    vector<pii> v(n + 1);
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        v[i] = {a, b};
        if (a <= k) ans = 1;
    }
    sort(v.begin() + 1, v.end(), [](pii &a, pii &b) {
        return a.second < b.second;
    });
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, inf));
    // 考慮 v[i] 時, 選 j 個的花費
    for (int i = 1; i <= n; i++) {
        // 滾動 dp，如果前面 dp[X][1] 有更新，每過下一層就影響力只 += 1
        for (int j = n; j >= 2; j--) {
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + v[i].first);
            // min(不選, 選)
            if (dp[i - 1][j - 1] + v[i].first + v[i].second <= k) { // 假如選了，更新 ans
                ans = max(ans, j);
            }
        }
        dp[i][1] = min(dp[i - 1][1], v[i].first - v[i].second);
    }
    cout << ans << endl;
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