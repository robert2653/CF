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
// 把所有 d 從 1 ~ d - 1 作為 start，做前綴和
// 區間查詢 = 前綴 - 區間前面有幾個 * 區間和 - 區間前的前綴和
// sqrt(n) 可以暴力解
void solve(){
    int n, q; cin >> n >> q;
    vector<int> nums(n);
    vector<int> ans(q);
    vector<vector<array<int, 3>>> queries(301, vector<array<int, 3>>());   // s, k, i;
    for(int i = 0; i < n; i++) cin >> nums[i];
    for(int i = 0; i < q; i++){
        int s, d, k; cin >> s >> d >> k;
        s--;
        if(d > 300){
            // brute force
            for(int j = 0; j < k; j++){
                ans[i] += (j + 1) * nums[s + j * d];
            }
        }
        else queries[d].push_back({s, k, i});
    }
    for(int d = 1; d <= 300; d++){
        vector<int> pref1(n), pref2(n);
        if(queries[d].size() == 0) continue;
        for(int j = 0; j < n; j++){
            if(j < d){
                pref1[j] = nums[j];
                pref2[j] = nums[j];
            }
            else {
                pref1[j] = pref1[j - d] + nums[j];
                pref2[j] = pref2[j - d] + nums[j] * (j / d + 1);
            }
        }
        // 區間查詢 = 前綴 - 區間前面有幾個 * 區間和 - 區間前的前綴和
        for(auto &[s, k, i] : queries[d]){
            int end = s + (k - 1) * d;
            ans[i] = pref2[end] - (s / d) * (pref1[end] - (s < d ? 0 : pref1[s - d])) - (s < d ? 0 : pref2[s - d]);
            // 195 - 2 * (195 - 129) - 
        }
    }
    for(auto &x : ans) cout << x << " ";
    cout << endl;
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