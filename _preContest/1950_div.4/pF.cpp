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
    int a, b, c; cin >> a >> b >> c;
    queue<int> q;
    if (a != c - 1) {
        cout << -1 << "\n";
        return;
    }
    q.push(0);
    int ans = 0;
    while (!q.empty()) {
 
        int f = q.front(); q.pop();
        ans = max(ans, f);
        if (a) {
            a--;
            q.push(f + 1);
            q.push(f + 1);
        }
        else if (b) {
            b--;
            q.push(f + 1);
        }
    }
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