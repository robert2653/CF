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
struct edge {
    int from; int to;
    int weight;
};
struct node {
    int sum;
};
const int llinf = 4e18;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
void solve(){
    int n, q; cin >> n >> q;
    vector<int> have1_pref(n + 1, 0);
    vector<int> remain_pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        have1_pref[i + 1] = have1_pref[i] + (x == 1 ? 1 : 0);
        remain_pref[i + 1] = remain_pref[i] + (x - 1);
    }
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        if (l == r) {
            cout << "No\n";
            continue;
        }
        if (remain_pref[r] - remain_pref[l - 1] >= have1_pref[r] - have1_pref[l - 1]) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}
signed main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}