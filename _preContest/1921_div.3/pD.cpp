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
    int x, y; cin >> x >> y;
    vector<int> vx(x), vy(y);
    for(int i = 0; i < x; i++) cin >> vx[i];
    for(int i = 0; i < y; i++) cin >> vy[i];
    sort(all(vx));
    sort(all(vy), greater<int>());
    int now = 0, ans = 0;
    vector<int> dis(x);
    int n = y - x;
    for(int i = 0; i < x; i++){
        dis[i] = abs(vx[i] - vy[i + n]);
        now += dis[i];
    }
    ans = now;
    for(int i = 0; i < x; i++){
        (now -= dis[i]) += abs(vx[i] - vy[i]);
        ans = max(ans, now);
        // cout << now << " ";
    }
    cout << ans << endl;
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