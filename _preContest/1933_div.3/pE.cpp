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
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        pref[i + 1] = pref[i] + tmp;
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int ans = -inf, id = inf;
        int start, u; cin >> start >> u;
        int l = start, r = n;
        while(l <= r) {
            int d = (r - l) / 3;
            int ml = l + d, mr = r - d;
            auto cal = [&](int ll, int rr) -> int {
                int sum = pref[rr] - pref[ll - 1];
                return u * sum - sum * (sum - 1) / 2;
            };
            int ansl = cal(start, ml);
            int ansr = cal(start, mr);
            if(ansl < ansr){
                l = ml + 1;
            }
            else r = mr - 1;
            if (ans < ansl || (ans == ansl && id > ml)) {
                ans = ansl;
                id = ml;
            }
            if (ans < ansr || (ans == ansr && id > mr)) {
                ans = ansr;
                id = mr;
            }
            // std::cout << ansl << " " << ansr << "\n";
            // cout << ans << " " << id << "\n";
        }
        std::cout << id << " ";
    }
    std::cout << "\n";
    
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