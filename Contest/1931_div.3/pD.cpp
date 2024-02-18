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
    int n, x, y; cin >> n >> x >> y;
    map<pii, int> mp;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int ans = 0;
    for(int i = n - 1; i >= 0; i--){
        int a = v[i] % x, b = v[i] % y;
        if(a == 0){
            auto it = mp.find(make_pair(0, b));
            if(it != mp.end()) ans += (*it).second;
        }
        else {
            auto it = mp.find(make_pair(x - a, b));
            if(it != mp.end()) ans += (*it).second;
        }
        // cout << a << " " << b << " ";
        // cout << ans << " ";
        mp[make_pair(a, b)]++;
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