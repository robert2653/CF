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
const int maxn = 1e6 + 5;
void solve(){
    int m, n, k; cin >> m >> n >> k;
    vector<pair<int, int>> rec(k + 1, pair<int, int>(0, 0));
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        if(x > k) continue;
        rec[x].first = 1;;
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x > k) continue;
        rec[x].second = 1;
    }
    int only_a = 0, only_b = 0, all = 0;
    for(int i = 1; i <= k; i++){
        if(!rec[i].first && !rec[i].second){
            cout << "No\n";
            return;
        }
        if(rec[i].first && !rec[i].second) only_a++;
        if(!rec[i].first && rec[i].second) only_b++;
        if(rec[i].first && rec[i].second) all++;
    }
    if(only_a + all < k / 2 || only_b + all < k / 2 || only_a + only_b + all < k){
        cout << "No\n";
    }
    else cout << "Yes\n";
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