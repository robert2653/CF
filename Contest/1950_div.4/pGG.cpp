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
    vector<string> g(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i] >> w[i];
    }
    vector<int> now, vis(n);
    int ans = n - 1;
    auto dfs = [&](auto self, int cnt) -> void {
        if (cnt == n) {
            for (int i = 0; i < (int)now.size() - 1; i++) {
                if (g[now[i]] != g[now[i + 1]] && w[now[i]] != w[now[i + 1]]) {
                    return;
                }
                ans = min(ans, n - (int)now.size());
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            self(self, cnt + 1);
            if (!vis[i]) {
                vis[i] = 1;
                now.push_back(i);
                self(self, cnt + 1);
                vis[i] = 0;
                now.pop_back();
            }
        }
    };
    dfs(dfs, 0);
    cout << ans << "\n";
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