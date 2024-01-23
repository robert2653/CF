#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define int long long
typedef pair<int, int> pii;
typedef struct {
    int w;
    int i; int j;
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
    set<array<int, 3>> edges;   // w, i, j
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int w; cin >> w;
            edges.insert({w, i, j});
        }
    }
    int pre_pop = m * n - m - n;
    while(pre_pop--){
        edges.erase(edges.begin());
    }
    while(true){
        edges.erase(edges.begin());
        set<array<int, 3>> tmp = edges;
        map<int, int> mp_row, mp_col;
        for(auto [w, i, j] : tmp){
            mp_row[i]++;
            mp_col[j]++;
        }
        int mxrow = 0, mxrownum = 0;
        int mxcol = 0, mxcolnum = 0;
        for(auto [i, n] : mp_row){
            if(n > mxrownum){
                mxrownum = n;
                mxrow = i;
            }
        }
        for(auto [j, n] : mp_col){
            if(n > mxcolnum){
                mxcolnum = n;
                mxcol = j;
            }
        }
        bool good = true;
        for(auto [w, i, j] : tmp){
            if(i != mxrow && j != mxcol){
                good = false;
                break;
            }
        }
        if(tmp.size() <= 3){
            cout << 1;
        }
        if(good){
            cout << mxrow + 1 << " " << mxcol + 1 << endl;
            return;
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