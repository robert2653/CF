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
    int n; cin >> n;
    int max_dep = 1, start = 1, end = 1;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dis(n + 1, 1);
    auto dfs = [&](auto self, int u, int pre) -> void {
        for (int v : adj[u]) {
            if (v == pre) continue;
            dis[v] = dis[u] + 1;
            if (dis[v] > max_dep){
                max_dep = dis[v];
                start = v;
            }
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);
    fill(all(dis), 1);
    vector<int> tbk(n + 1, 0);
    max_dep = 1;
    auto dfs2 = [&](auto self, int u, int pre) -> void {
        for (int v : adj[u]) {
            if (v == pre) continue;
            tbk[v] = u;
            dis[v] = dis[u] + 1;
            if (dis[v] > max_dep){
                max_dep = dis[v];
                end = v;
            }
            self(self, v, u);
        }
    };
    dfs2(dfs2, start, 0);
    // cerr << max_dep << "\n";
    if (max_dep % 4 == 0) {
        cout << max_dep / 2 << "\n";
        for (int i = 1; i < max_dep / 2; i++) {
            end = tbk[end];
        }
        for (int i = 1; i <= max_dep / 2; i += 2) {
            cout << end << " " << i << "\n";
        }
        end = tbk[end];
        for (int i = 1; i <= max_dep / 2; i += 2) {
            cout << end << " " << i << "\n";
        }
    }
    else {
        cout << max_dep / 2 + 1 << "\n";
        for (int i = 0; i < max_dep / 2; i++) {
            end = tbk[end];
        }
        for (int i = 0; i <= max_dep / 2; i++) {
            cout << end << " " << i << "\n";
        }
    }
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