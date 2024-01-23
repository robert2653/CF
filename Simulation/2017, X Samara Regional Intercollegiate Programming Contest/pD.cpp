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
    int n, k; cin >> n >> k;
    k = abs(k);
    vector<int> v(n + 1);
    v[0] = 0;
    for(int i = 1; i <= n; i++) cin >> v[i];
    sort(all(v));
    vector<int> vv(n);
    for(int i = 1; i <= n; i++){
        vv[i - 1] = v[i] - v[i - 1];
    }
    for(auto &i : vv){
        if(k % i == 0){
            cout << "YES\n";return;
        }
    }
    cout << "NO\n";
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