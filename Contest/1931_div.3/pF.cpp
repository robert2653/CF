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
    int n, m;
    cin >> n >> m;
    vector<int> in(n + 1, 0);
    vector<vector<int>> graph(n + 1, vector<int>());
    for(int i = 0; i < m; i++){
        int useless; cin >> useless;
        int pre = 0;
        for(int j = 1; j < n; j++){
            int now; cin >> now;
            if(j != 1){
                in[now]++;
                graph[pre].push_back(now);
            }
            pre = now;
        }
        // cout << pre << " ";
    }
    queue<int> q;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int now = q.front(); q.pop();
        ans.push_back(now);
        for(auto nxt : graph[now]){
            in[nxt]--;
            if(in[nxt] == 0) q.push(nxt);
        }
    }
    if(ans.size() == n){
        cout << "Yes\n";
    }
    else cout << "No\n";
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