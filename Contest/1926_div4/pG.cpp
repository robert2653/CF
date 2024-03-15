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
#include <bits/stdc++.h>
using namespace std;
void dfs(int now, vector<vector<int>> &tree, vector<array<int, 3>> &dp, string &s) {
    // S P C
    if (s[now] == 'S') { dp[now] = {inf, 0, inf}; }
    else if (s[now] == 'P') { dp[now] = {inf, inf, 0}; }
    else { dp[now] = {0, inf, inf}; }
    for (auto nxt : tree[now]) {
        dfs(nxt, tree, dp, s);
        array<int, 3> tmp;
        tmp.fill(inf);
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                if ((a | b) != 3) {
                    tmp[a | b] = min(tmp[a | b], dp[now][a] + dp[nxt][b]);
                }
                tmp[a] = min(tmp[a], dp[now][a] + dp[nxt][b] + 1);
            }
        }
        dp[now] = tmp;
    }
}
void solve(){
    int n; cin >> n;
    vector<int> v(n + 1);
    for(int i = 2; i <= n; i++){
        cin >> v[i];
    }
    string s; cin >> s;
    s = "0" + s;
    vector<vector<int>> tree(n + 1, vector<int>());
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        tree[v[i]].push_back(i);
    }
    vector<array<int, 3>> dp(n + 1, {0, 0, 0});
    dfs(1, tree, dp, s);
    cout << min({dp[1][0], dp[1][1], dp[1][2]}) << endl;
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