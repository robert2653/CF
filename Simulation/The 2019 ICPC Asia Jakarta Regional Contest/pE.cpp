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
    int n, L, R, K; cin >> n >> L >> R >> K;
    vector<int> v(n), l(n, L), r(n, R);
    // l, r 維護最大有效區間
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i == 0) continue;
        if(v[i - 1] == v[i]){
            l[i] = l[i - 1];
            r[i] = r[i - 1];
        }
        // 遞增，l++, r+=k
        else if(v[i - 1] < v[i]){
            l[i] = l[i - 1] + 1;
            r[i] = min(r[i - 1] + K, R);
        }
        // 遞減，l-=k, r--
        else {
            l[i] = max(l[i - 1] - K, L);
            r[i] = r[i - 1] - 1;
        }
        if(l[i] > r[i]) {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> ans(n, l.back());
    for(int i = n - 1; i > 0; i--){
        if(v[i - 1] == v[i]){
            ans[i - 1] = ans[i];
        }
        else if(v[i - 1] < v[i]){
            ans[i - 1] = max(ans[i] - K, l[i - 1]);
        }
        else {
            ans[i - 1] = max(ans[i] + 1, l[i - 1]);
        }
    }

    for(auto i : ans) cout << i << " ";
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