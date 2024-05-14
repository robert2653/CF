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
    int e, k, q; cin >> e >> k >> q;
    vector<int> a(k + 1);
    a[0] = 0;
    vector<int> b(k + 1);
    b[0] = 0;
    for (int i = 1; i <= k; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];
    while (q--) {
        int x; cin >> x;
        int d = --upper_bound(a.begin(), a.end(), x) - a.begin();
        //  time / (y - x) * (q - x);
        if (a[d + 1] == a[d]) cout << b[d] << "\n";
        else cout << b[d] + (b[d + 1] - b[d]) * (x - a[d]) / (a[d + 1] - a[d]) << " ";
    }
    cout << "\n";
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