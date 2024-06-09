#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using ll = long long;

using namespace __gnu_pbds;
template<typename T>
using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using pbds_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int ans = 0;
    pbds_multiset<int> st1, st2;
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        st1.insert(a[i]);
        st2.insert(a[i]);
        if (st1.size() == 3) {
            st1.erase(st1.upper_bound(i - 3));
        }
        if (st1.size() == 2) {
            ans = max(ans, *st1.find_by_order(0));
        }
        if (st2.size() == 4) {
            st2.erase(st2.upper_bound(i - 4));
        }
        if (st2.size() == 3) {
            ans = max(ans, *st2.find_by_order(1));
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}