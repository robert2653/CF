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
    string s; cin >> s;
    int n = s.size();
    int ans = 1;
    int now = 0;
    int flag = 0;
    int turn = s[0] - '0';
    for (int i = now; i < n; i++) {
        if (i < n - 1 && s[i] == '0' && s[i + 1] == '1' && !flag) {
            ans--;
            flag = 1;
        }
        if (s[i] - '0' != turn) {
            ans++;
            turn = s[i] - '0';
        }
    }
    cout << ans << endl;
}

signed main() {
    // ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}