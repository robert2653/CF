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
    string arr[2];
    cin >> arr[0] >> arr[1];
    string path; path.push_back(arr[0][0]);
    // 不能往上，所以下面為 0，右邊 1 就要往下，然後一路到底
    // 找到 path，然後 bfs dp
    queue<pii> q;
    bool down = false;
    for (int i = 1; i < n; i++) {
        if (down) {
            path.push_back(arr[1][i]);
        }
        else {
            if (arr[0][i] > arr[1][i - 1]) {
                down = 1;
                path.push_back(arr[1][i - 1]);
                path.push_back(arr[1][i]);
            }
            else path.push_back(arr[0][i]);
        }
    }
    if (!down) path.push_back(arr[1][n - 1]);
    q.push({1, 1});
    vector<vector<int>> dp(2, vector<int>(n));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i < n && arr[0][i] == path[i]) { // 右
            dp[0][i] += dp[0][i - 1];
        }
        if (arr[1][i - 1] == path[i]) { // 下
            dp[1][i - 1] += dp[0][i - 1];
        }
        if (i >= 2 && arr[1][i - 1] == path[i]) { // 下右
            dp[1][i - 1] += dp[1][i - 2];
        }
    }
    cout << path << "\n";
    cout << dp[1][n - 1] << "\n";
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