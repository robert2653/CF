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
    int n; cin >> n;
    vector<int> v(n);
    vector<int> pref(n), suf(n), vis(n);
    int x = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        vis[v[i]] = 1;
        while (vis[x]) {
            x++;
        }
        pref[i] = x;
    }
    vis.assign(n, 0);
    x = 0;
    for (int i = n - 1; i > 0; i--) {
        vis[v[i]] = 1;
        while (vis[x]) {
            x++;
        }
        suf[i] = x;
    }
    for (int i = 0; i < n - 1; i++) {
        if (pref[i] == suf[i + 1]) {
            cout << 2 << "\n";
            cout << 1 << " " << i + 1 << "\n";
            cout << i + 2 << " " << n << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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