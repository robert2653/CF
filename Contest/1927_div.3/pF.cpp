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
const int maxn = 2e5 + 5;

struct DSU {
    vector<int> boss, siz;
    DSU (int n){
        boss.resize(n + 1);
        iota(boss.begin(), boss.end(), 0);
        siz.assign(n + 1, 1);
    }
    int find_boss(int x){
        if(boss[x] == x) return x;
        return boss[x] = find_boss(boss[x]);
    }
    bool same(int x, int y) {
        return find_boss(x) == find_boss(y);
    }
    bool merge(int x, int y){
        x = find_boss(x);
        y = find_boss(y);
        if (x == y) {
            return false;
        }
        if(siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        boss[y] = x;
        return true;
    }
    int size(int x){
        return siz[find_boss(x)];
    }
};
void dfs(int u, int par, int W, int U, int V, vector<int> &parv, vector<vector<int>> &graph){
    parv[u] = par;
    for(auto v : graph[u]){
        if(v == par) continue;
        if(v == V){
            vector<int> ans;
            ans.push_back(V);
            while(u != U){
                ans.push_back(u);
                u = parv[u];
            }
            ans.push_back(U);
            cout << W << " " << ans.size() << endl;
            for(auto i: ans) cout << i << " ";
            cout << endl;
            break;
        }
        dfs(v, u, W, U, V, parv, graph);
    }
}
void solve(){
    int n, m; cin >> n >> m;
    vector<edge> edges(m);
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    sort(all(edges), [](edge a, edge b) { return a.weight > b.weight; });
    DSU dsu(n);
    int ans, U, V;
    for(auto [u, v, w] : edges){
        if(!dsu.merge(u, v)){
            ans = w;
            U = u;
            V = v;
        }
        else {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    // 建成樹，最小環在我們的 U, V 虛擬邊
    // 因為是樹，也不需要 vis 了
    vector<int> parv(n + 1);
    dfs(U, U, ans, U, V, parv, graph);
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