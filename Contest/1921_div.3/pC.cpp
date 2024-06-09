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
    int n, f, a, b; cin >> n >> f >> a >> b;
    int pre = 0;
    bool flag = true;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        f -= min(a * (x - pre), b);
        if(f <= 0){
            flag = false;
        }
        pre = x;
    }
    cout << (flag ? "YES" : "NO") << endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}