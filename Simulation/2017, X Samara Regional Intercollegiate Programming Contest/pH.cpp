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
    int m, n; cin >> m >> n;
    int graph[m][n];
    int mx = 0;
    int mx_row, mx_col;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
            if(graph[i][j] > mx) {
                mx = graph[i][j];
                mx_row = i;
                mx_col = j;
            }
        }
    }
    int ans3 = 0;
    int m2x_row, m2x_col;
    int m2x = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == mx_row || j == mx_col) continue;
            if(graph[i][j] > m2x) {
                m2x = graph[i][j];
                m2x_row = i;
                m2x_col = j;
                ans3 = max(ans3, graph[i][j]);
            }
        }
    }
    int ans1x = mx_row, ans1y = m2x_col, ans2x = m2x_row, ans2y = mx_col;
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == ans1x || j == ans1y) continue;
            if(graph[i][j] > ans1) {
                ans1 = graph[i][j];
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == ans2x || j == ans2y) continue;
            if(graph[i][j] > ans2) {
                ans2 = graph[i][j];
            }
        }
    }
    if((ans1 > ans2 && ans2 > ans3) || (ans2 > ans1 && ans1 > ans3)) {
        cout << mx_row + 1 << " " << mx_col + 1 << endl;
    }
    else if((ans1 > ans3 && ans3 > ans2) || (ans3 > ans1 && ans1 > ans2)) {
        cout << ans2x + 1 << " " << ans2y + 1 << endl;
    }
    else {
        cout << ans1x + 1 << " " << ans1y + 1 << endl;
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