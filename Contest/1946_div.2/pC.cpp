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
const int llinf = 4e18;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

void solve() {
    int n, k; cin >> n >> k;
    int max_dep = 1, start = 1, end = 1;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> sz(n + 1, 1);
    int cnt = 0;
    int m = 0;
    auto dfs = [&](auto self, int u, int pre) -> void {
        for (int v : adj[u]) {
            if (v == pre) continue;
            self(self, v, u);
            if (sz[v] >= m) {
                cnt++;
                sz[v] = 0;
            }
            else sz[u] += sz[v];
        }
    };
    int l = 1, r = n;
    while (l <= r) {
        fill(all(sz), 1);
        cnt = 0;
        m = (l + r) / 2;
        dfs(dfs, 1, 1);
        if (sz[1] >= m) cnt++;
        if (cnt > k) {
            l = m + 1;
        }
        else r = m - 1;
    }
    cout << r << "\n";
}
signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}