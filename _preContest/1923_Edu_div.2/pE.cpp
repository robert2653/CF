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
    vector<map<int, int>> vmp(n + 1);
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<int> color(n + 1);
    for (int i = 1; i <= n; i++) cin >> color[i];
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    auto dfs = [&](auto self, int now, int par) -> void {
        for (auto nxt : adj[now]) {
            if (nxt == par) continue;
            self(self, nxt, now);
            if (vmp[nxt].count(color[now])) {   // 以 par 為主
                ans += vmp[nxt][color[now]];
                vmp[nxt].erase(color[now]);
            }
            if (vmp[nxt].size() > vmp[now].size()) swap(vmp[now], vmp[nxt]);    // 壓複雜度
            for (auto [a, b] : vmp[nxt]) {  // 子節點互相排列組合
                ans += 1LL * b * vmp[now][a];
                vmp[now][a] += b;
            }
            vmp[nxt].clear();
        }

        vmp[now][color[now]]++;
    };
    dfs(dfs, 1, 1);
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