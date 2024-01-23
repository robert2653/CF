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
// 對於每個字串，會有先備人數，跟經過他的人數變化
// 分兩個 pq
// 可以 push: 依人數變化大到小排列 (push 前先比較先備，不夠要丟回去另一個 pq)，
// 不能 push: 依照先備人數小到大
struct piece {
    int pre;
    int gain;
};
piece process(string s){
    piece p = {0, 0};
    int cnt = 0;
    for(auto &c : s){
        if(c == '('){
            p.gain++;
            cnt++;
        }
        else {
            if(cnt) cnt--;
            else p.pre++;
            p.gain--;
        }
    }
    return p;
}
struct cmp {
    bool operator()(const array<int, 3> &a, const array<int, 3> &b){
        return a[1] > b[1]; // 小到大
    }
};
void solve(){
    int n; cin >> n;
    priority_queue<array<int, 3>> can_push;    // 人數變化、先備人數、id
    priority_queue<array<int, 3>, vector<array<int, 3>>, cmp> cant_push; // 人數變化、先備人數、id
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        piece p = process(s);
        // cout << p.gain << " " << p.pre << "\n";
        if(p.pre == 0){
            can_push.push({p.gain, p.pre, i});
        }
        else {
            cant_push.push({p.gain, p.pre, i});
        }
    }
    int now = 0;
    while(!can_push.empty()){
        auto [gain, pre, id] = can_push.top();
        can_push.pop();
        if(pre > now){
            cant_push.push({gain, pre, id});
        }
        else {
            ans.push_back(id);
            now += gain;
        }
        while(!cant_push.empty() && cant_push.top()[1] <= now){
            can_push.push(cant_push.top());
            cant_push.pop();
        }
    }
    if(ans.size() == n && now == 0){
        cout << "YES\n";
        for(auto &i : ans) cout << i << " ";
    }
    else cout << "NO\n";
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