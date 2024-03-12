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
    int n, m, k, d; cin >> n >> m >> k >> d;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        vector<int> v(m + 1), dp(m + 1);
        multiset<int> st;
        cin >> v[1]; v[1] += 1; dp[1] = v[1]; st.insert(v[1]);
        for (int j = 2; j < m; j++) {
            cin >> v[j]; v[j] += 1;
            dp[j] = *st.begin() + v[j];
            st.insert(dp[j]);
            if (st.size() == d + 2) {
                st.erase(st.find(dp[j - d - 1]));
            }
        }
        cin >> v[m]; v[m] += 1; dp[m] = *st.begin() + v[m];
        ans[i] = dp[m];
    }
    int pref = 0;
    for (int i = 0; i < k; i++) {
        pref += ans[i];
    }
    int mn = pref;
    for (int l = 0, r = k; r < n; l++, r++) {
        pref -= ans[l];
        pref += ans[r];
        mn = min(mn, pref);
    }
    cout << mn << endl;
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