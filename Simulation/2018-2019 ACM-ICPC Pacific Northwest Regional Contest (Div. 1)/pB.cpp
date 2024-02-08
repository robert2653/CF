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
using pbds_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
const int maxn = 1e7 + 5;
void solve(){
    int al, ar, bl, br; cin >> al >> ar >> bl >> br;
    vector<int> wei(maxn, 0);
    // 只要找次方項為一的，然後用排容原理
    int n = max(ar, br);
    int ans = (ar - al + 1) * (br - bl + 1);
    for (int i = 2; i <= n; i++) {
        if (wei[i] == -1) continue;
        if (wei[i] == 0) {
            wei[i] = 1;
            for (int j = 2; i * j <= n; j++) {
                // cerr << "i : " << i << ", j : " << j << "\n";
                if (j % i == 0) wei[i * j] = -1;  // 次方不為1
                else if (wei[i * j] != -1) wei[i * j]++;
            }
        }// 12
        // 1 2 3 4 5 6 7 8 9 10 11 12
        int a = ar / i - (al - 1) / i;
        int b = br / i - (bl - 1) / i;
        ans += (wei[i] & 1 ? -1 : 1) * a * b;
        // cerr << ans << " " << a << " " << b << " " << i << endl;
    }
    // cout << wei[12] << "\n";
    cout << ans << endl;
}
signed main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}