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
int cal(int m, vector<int> &v, int gain, int cost){
    int ans = 0;
    for(auto &i : v){
        int remain = i % m;   // 5 3, 2 2 1
        int tmp = i / m;    // 1
        ans += gain * (tmp + 1) * (i - tmp - 1) * (remain);
        ans += gain * tmp * (i - tmp) * (m - remain);
    }
    ans >>= 1;
    ans -= cost * (m - 1);
    // cout << m << " " << ans << endl;
    return ans;
}
void solve(){
    int n, gain, cost; cin >> n >> gain >> cost;
    vector<int> v(n);
    int mx = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    int l = 1, r = mx;
    int ans = 0;
    // for(int i = l; i <= r; i++){
    //     ans = max(ans, cal(i, v, gain, cost));
    //     cout << i << " " << ans << endl;
    // }
    while(l < r) {
        int d = (r - l) / 3;
        int ml = l + d, mr = r - d;
        int ansl = cal(ml, v, gain, cost);
        int ansr = cal(mr, v, gain, cost);
        if(ansl < ansr){
            l = ml + 1;
        }
        else r = mr - 1;
        ans = max({ans, ansl, ansr});
        // cout << l << " " << r << " " << ans << endl;
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