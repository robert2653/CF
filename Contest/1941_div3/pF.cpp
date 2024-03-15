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
    int n, m; cin >> n >> m;
    map<pii, int> dis;
    vector<int> ans(n + 1, inf);
    vector<map<int, vector<int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        adj[u][c].push_back(v);
        adj[v][c].push_back(u);
    }
    int b, e; cin >> b >> e;
    deque<array<int, 3>> dq;
    dq.push_back({0, b, 0});
    while(!dq.empty()){
        auto [d, u, c] = dq.front(); dq.pop_front();
        if(dis.count({u, c})) continue;
        dis[{u, c}] = d;
        ans[u] = min(ans[u], d);
        if (c) {
            dq.push_front({d, u, 0});   // 先別往下找，會 MLE
            for (auto v : adj[u][c]) {
                dq.push_front({d, v, c});
            }
        }
        else {
            for (auto nxt : adj[u]) {
                dq.push_back({d + 1, u, nxt.first});
            }
        }
    }
    cout << ans[e] << "\n";
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