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
    // 移掉或是++
    int n; cin >> n;
    int sum = 0;
    vector<int> v(n);
    array<int, 3> modarr({0, 0, 0});
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
        modarr[v[i] % 3]++;
    }
    if (sum % 3 == 0) {
        cout << 0 << "\n";
    }
    else if (sum % 3 == 2) {
        cout << 1 << "\n";
    }
    else {  // 1，移掉
        if (modarr[1]) {
            cout << 1 << "\n";
        }
        else cout << 2 << "\n";
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