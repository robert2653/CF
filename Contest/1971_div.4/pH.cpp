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

//  at least 2 of (x,y,z) are true ⟺
//  at least one of (x,y) is true &&
//  at least one of (y,z) is true && 
//  at least one of (z,x) is true.

void solve() {
    int n; cin >> n;
    vector g(3, vector<int>(n));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    vector<bool> ans(n);
    vector sat(n * 2, vector<int>());
    // 建邊
    for (int i = 0; i < n; i++) {
        for (int a = 0; a < 3; a++) {
            for (int b = a + 1; b < 3; b++) {
                int u = abs(g[a][i]) - 1, v = abs(g[b][i]) - 1;
                bool x = g[a][i] > 0, y = g[b][i] > 0;
                sat[u * 2 + !x].push_back(v * 2 + y);
                sat[v * 2 + !y].push_back(u * 2 + x);
            }
        }
    }
    // tarjan
    vector<int> id(n * 2, -1), dfn(n * 2, -1), low(n * 2, -1);
    vector<int> stk;
    int now = 0, cnt = 0;
    function<void(int)> tarjan = [&](int u) {
        stk.push_back(u);
        dfn[u] = low[u] = now++;
        for (auto v : sat[u]) {
            if (dfn[v] == -1) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            } else if (id[v] == -1) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            int v;
            do {
                v = stk.back();
                stk.pop_back();
                id[v] = cnt;
            } while (v != u);
            ++cnt;
        }
    };
    for (int i = 0; i < 2 * n; ++i) if (dfn[i] == -1) tarjan(i);
    for (int i = 0; i < n; ++i) {
        if (id[2 * i] == id[2 * i + 1]) {
            cout << "NO\n";
            return;
        }
        ans[i] = id[2 * i] > id[2 * i + 1];
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}