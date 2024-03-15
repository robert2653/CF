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
void solve(){
    string s; cin >> s;
    int sz = s.size();
    for (int i = sz / 2; i >= 1; i--) {
        int l = 0, r = i * 2 - 1;
        while (r < sz) {
            bool b = true;
            for (int k = l; k < l + i; k++) {
                if (s[k] == s[k + i] || s[k] == '?' || s[k + i] == '?') {
                    continue;
                }
                else {
                    b = false;
                    break;
                }
            }
            if (b) {
                cout << i * 2 << "\n";
                return;
            }
            if (r + 1 == sz) {
                break;
            }
            l++; r++;
        }
    }
    cout << 0 << "\n";
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