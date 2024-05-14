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
    int m, n; cin >> m >> n;
    vector<vector<int>> graph(m, vector<int>(n));
    vector<vector<int>> dis(m, vector<int>(n, inf));
    for (int i = 0; i < m; i++) {
        for (int j = 0; i < n; j++) {
            cin >> graph[i][j];
        }
    }
    // 往上走是騙人的，沒有用，往下相當於走 2 步，往右相當走右下
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pq.push({0, 0, 0}); dis[0][0] = 0;
    while (!pq.empty()) {
        auto [w, i, j] = pq.top(); pq.pop();
        if (y < m - 1 && a[(x + 1) % n][y + 1] == 0 && dis[(x + 1) % n][y + 1] == -1) {
            dis[(x + 1) % n][y + 1] = dis[x][y] + 1;
            q.emplace((x + 1) % n, y + 1);
        }
        if (a[(x + 1) % n][y] == 0 && a[(x + 2) % n][y] == 0 && dis[(x + 2) % n][y] == -1) {
            dis[(x + 2) % n][y] = dis[x][y] + 1;
            q.emplace((x + 2) % n, y);
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