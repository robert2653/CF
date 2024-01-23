#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define int long long
typedef pair<int, int> pii;
typedef struct {
    int from; int to;
    int weight;
} edge;
typedef struct {
    int sum;
} Node;
const int llinf = 4e18;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

void solve(){
    int n; cin >> n;
    priority_queue<pair<int ,int>, vector<pii>, greater<pii> > pq;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        int tmp; cin >> tmp;
        if(tmp == 0) q.push(i);
        else {
            pq.push({tmp, i});
        }
    }
    vector<pii> ans;
    while(!q.empty() && !pq.empty()){
        int v = q.front(); q.pop();
        auto u = pq.top(); pq.pop();
        u.first--;
        if(u.first == 0){
            q.push(u.second);
        }
        else {
            pq.push({u.first, u.second});
        }
            ans.push_back({u.second, v});
    }
    if(pq.size() != 0){
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for(auto &[u, v] : ans){
            cout << u << " " << v << "\n";
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}