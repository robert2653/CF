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
    string s;
    vector<pair<int, int>> v;
    // set<pair<int, int>> st;
    for (int i = 0; i < 21; i++) {
        cin >> s;
        int a = 0, b = 0;
        for (int i = 0; i < 21; i++) {
            if (s[i] == '1') a++;
            else b++;
        }
        v.push_back({a, b});
        // st.insert({a, b});
    }
    int ans = 0;
    sort(all(v));
    int cnt = 0;
    for (int i = 0; i < 21; i++) {
        // if (v[i - 1] == v[i]) {
        //     if (!cnt) cnt = 2;
        //     else cnt++;
        // }
        // else {
        //     ans += cnt;
        //     cnt = 0;
        // }
        ans += v[i].second - v[i].first;
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
    // cin >> t;
    while (t--) {
        solve();
    }
}