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

void solve(map<int, int> &mp){
    int x; cin >> x;
    int x2 = x;
    int ans = x / 30;
    ans *= 2;
    x %= 30;
    ans += mp[x];
    
    int ans2 = 0;
    if (x2 >= 15) {
        x2 -= 15;
        ans2++;
    }
    ans2 += (x2 / 30) * 2;
    x2 %= 30;
    ans2 += mp[x2];
    cout << min(ans, ans2) << "\n";
}
signed main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    map<int, int> mp;
    for (int i = 1; i <= 30; i++) {
        mp[i] = inf;
    }
    for (int one = 0; one <= 30; one++) {
        for (int three = 0; three <= 10; three++) {
            for (int ten = 0; ten <= 3; ten++) {
                for (int fif = 0; fif <= 2; fif++) {
                    for (int six = 0; six <= 5; six++) {
                        int x = one * 1 + three * 3 + ten * 10 + fif * 15 + six * 6;
                        if (x < 30) {
                            mp[x] = min(mp[x], one + three + ten + fif + six);
                        }
                    }
                }
            }
        }
    }
    // for (auto [i, j] : mp) {
    //     cout << i << " " << j << endl;
    // }
    cin >> t;
    while(t--){
        solve(mp);
    }
}