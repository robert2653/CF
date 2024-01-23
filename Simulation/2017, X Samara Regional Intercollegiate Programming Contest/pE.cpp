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
    int n, m; cin >> n >> m;
    int ans = 0;
    vector<int> tel(n), bo(m);
    for(int i = 0; i < n; i++) cin >> tel[i];
    for(int i = 0; i < m; i++) cin >> bo[i];
    bo.erase(unique(all(bo)), bo.end());
    auto it = lower_bound(all(bo), tel[0]);
    if(it != bo.begin()){
        ans += 2LL * abs(bo[0] - tel[0]);
    }
    // cout << ans << endl;
    it = upper_bound(all(bo), tel[n - 1]);
    if(it != bo.end()){
        ans += 2LL * abs(bo[m - 1] - tel[n - 1]);
    }
    // cout << ans << endl;
    for(int i = 0; i < n - 1; i++){
        // tel
        it = upper_bound(all(bo), tel[i]);
        auto en = --lower_bound(all(bo), tel[i + 1]);
        int cnt = en - it + 1;
        if(cnt == 1){
            ans += 2 * min(bo[it - bo.begin()] - tel[i], tel[i + 1] - bo[en - bo.begin()]);
        }
        else if(cnt >= 2){
            int mn = tel[i + 1] - tel[i];
            int l = it - bo.begin(), r = l + 1;

            int rr = l + cnt - 1;
            mn = min({mn, 2 * (tel[i + 1] - bo[l]), 2 * (bo[rr] - tel[i])});

            for(int j = 1; j <= cnt - 1; j++){
                mn = min(mn, 2LL * (bo[l] - tel[i]) + 2LL * (tel[i + 1] - bo[r]));
                l++, r++;
            }
            ans += mn;
        }

    }
    cout << ans << endl;

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