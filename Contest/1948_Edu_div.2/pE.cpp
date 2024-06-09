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
    int ans = (n - 1) / k + 1;  // k 的數字一組，k/2 ~ 1、k~k/2+1
    vector<int> v(n), id(n);
    int now = 0;
    for (int i = 0; i < ans; i++) {
        int l = i * k + 1, r = min(k * (i + 1), n); // 數字
        int m = (l + r) / 2;
        for (int x = m; x >= l; x--, now++) {
            v[now] = x;
            id[now] = i + 1;
        }
        for (int x = r; x > m; x--, now++) {
            v[now] = x;
            id[now] = i + 1;
        }
    }
    for (int i : v) cout << i << " ";
    cout << "\n" << ans << "\n";
    for (int i : id) cout << i << " ";
    cout << "\n";
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