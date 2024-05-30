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
void solve(vector<int> &ans){
    // 0 1 2 3 4 5 6 7 8 9 45
    // 1 2 3 4 5 6 7 8 9 10 55
    // 2 3 4 5 6 7 8 9 10 11 65...135
    // 每多10 += 10
    // 100 : 1 2 3 4 5 6 7 8 9 10~199 : 235
    // 200 : 2 3 4 5 6 7 8 9 10 11: 335...1035
    // 1000: 
    int x; cin >> x;
    cout << ans[x] << "\n";

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
    vector<int> v(2e5 + 1, 0);
    for (int i = 1; i <= 2e5; i++) {
        string s = to_string(i);
        int ans = 0;
        for (auto c : s) ans += c - '0';
        v[i] = v[i - 1] + ans;
    }
    while(t--){
        solve(v);
    }
}