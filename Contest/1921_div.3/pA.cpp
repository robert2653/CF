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
    set<int> sx, sy;
    int tmp;
    cin >> tmp; sx.insert(tmp);
    cin >> tmp; sy.insert(tmp);
    cin >> tmp; sx.insert(tmp);
    cin >> tmp; sy.insert(tmp);
    cin >> tmp; sx.insert(tmp);
    cin >> tmp; sy.insert(tmp);
    cin >> tmp; sx.insert(tmp);
    cin >> tmp; sy.insert(tmp);
    cout << abs(*sx.begin() - *sx.rbegin()) * abs(*sy.begin() - *sy.rbegin()) << endl;
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
