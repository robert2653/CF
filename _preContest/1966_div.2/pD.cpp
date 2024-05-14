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
    vector<int> ans(25), pref(25), suf(25);
    for (int i = 0; i < 25; i++) {
        ans[i] = 1 << i;
        pref[i] = (i == 0 ? 0 : pref[i - 1]) + ans[i];
    }
    if (k == 1) {
        ans[0] = 2;
        ans.pop_back();
        ans.insert(ans.begin() + 1, 3);
    }
    else {
        int l = 0, r = 24;
        int id = (lower_bound(all(pref), k)) - pref.begin();
        ans[id] = k - pref[id - 1] - 1;
        ans[id + 1] = k + 1;
        for (int i = id + 2; i < 25; i++) {
            ans[i] = ans[i - 1] * 2;
        }
        ans.back() = k * 2 + 1;
    }
    cout << 25 << "\n";
    for (auto &i : ans) cout << i << " ";
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