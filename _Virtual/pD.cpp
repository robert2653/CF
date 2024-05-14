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
    vector<int> v(n);
    vector<vector<int>> pref(n, vector<int>(32));
    vector<vector<int>> odd_pref(n, vector<int>(32));
    vector<vector<int>> even_pref(n, vector<int>(32, 1));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v[i] = x;
        for (int j = 0; j < 32; j++) {
            pref[i][j] = pref[i - 1][j] + (x >> j & 1);
            if (x >> j & 1) {
                odd_pref[i][j] = even_pref[i - 1][j] + 1;
                even_pref[i][j] = odd_pref[i - 1][j] + 1;
            }
            else {
                odd_pref[i][j] = odd_pref[i - 1][j] + 1;
                even_pref[i][j] = even_pref[i - 1][j] + 1;
            }
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