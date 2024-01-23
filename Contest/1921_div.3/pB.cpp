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
    // 01, 10 => +1;
    // 剩下++;
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    int n01 = 0, n02 = 0;
    for(int i = 0; i < n; i++){
        if(s1[i] == '0' && s2[i] == '1') n01++;
        if(s1[i] == '1' && s2[i] == '0') n02++;
    }
    cout << n01 + n02 - min(n01, n02) << endl;
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