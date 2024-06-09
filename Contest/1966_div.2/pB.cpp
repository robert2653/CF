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
    int m, n; cin >> m >> n;
    int bl = n, bu = m, br = 1, bd = 1, wl = n, wu = m, wr = 1, wd = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            if (c == 'B') {
                bl = min(bl, j);
                bu = min(bu, i);
                br = max(br, j);
                bd = max(bd, i);
            }
            if (c == 'W') {
                wl = min(wl, j);
                wu = min(wu, i);
                wr = max(wr, j);
                wd = max(wd, i);
            }
        }
    }
    if (bl == 1 && br == n && bu == 1 && bd == m) {
        cout << "YES\n";
    }
    else if (wl == 1 && wr == n && wu == 1 && wd == m) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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