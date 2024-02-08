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
    string m, f; cin >> m >> f;
    int sz = m.size();
    int same = 0, insame = 0;
    for(int i = 0; i < sz; i++){
        if(m[i] == f[i]) same++;
        else insame++;
    }
    if(n < same){
        cout << n + insame;
    }
    else {
        cout << max(insame - n + same, sz - n + same);
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