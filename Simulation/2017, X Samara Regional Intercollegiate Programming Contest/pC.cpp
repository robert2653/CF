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

// 3 7 2
// 8 1
// min(a + c, n), min(b + c, m) 4
void solve(){
    int r, g, un; cin >> r >> g >> un;
    int n, m; cin >> n >> m;
    if(r + un <= n && g + un <= m){
        cout << r + g + un << endl;
    }
    else {
        int a, b;
        if(r + un >= n) a = n;
        else a = r + un + min(g, m);
        if(g + un >= m) b = m;
        else b = g + un + min(r, n);
        cout << min(a, b) << endl;
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