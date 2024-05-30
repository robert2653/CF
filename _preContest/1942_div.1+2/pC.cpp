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
    int n, x, y; cin >> n >> x >> y;
    vector<int> v(x);
    for (int i = 0; i < x; i++) {
        cin >> v[i];
    }
    sort(all(v));
    vector<int> v2;
    int ans = n - 2;
    int cnt = 1;
    vector<int> dis(x);
    for (int i = 0; i < x; i++) {
        dis[i] = (v[(i + 1) % x] - v[i] + n) % n;
        if (dis[i] >= 3) ans -= dis[i] - 1;
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