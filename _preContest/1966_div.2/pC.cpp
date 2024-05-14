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
    deque<int> dq(n);
    for (int i = 0; i < n; i++) cin >> dq[i];
    sort(all(dq));
    dq.erase(unique(all(dq)), dq.end());

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (dq[0] == 1) cnt++;
            else break;
        }
        if (i < n - 1) {
            if (dq[i] + 1 == dq[i + 1]) {
                cnt++;
            }
            else break;
        }
    }
    for (int i = 0; i < cnt; i++) dq.pop_front();
    if (cnt & 1) {  // bob turn 
        // if (dq.size() & 1) {
        //     cout << "Bob\n";
        // }
        // else {
        //     cout << "Alice\n";
        // }
        if (dq.size()) cout << "Bob\n";
        else cout << "Alice\n";
    }
    else {
        // if (dq.size() & 1) {
        //     cout << "Alice\n";
        // }
        // else {
        //     cout << "Bob\n";
        // }
        if (dq.size()) cout << "Alice\n";
        else cout << "Bob\n";
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