#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int> 
#define endl "\n"
#define int long long
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using pbds_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct edge {
    int from; int to;
    int weight;
};
struct node {
    int sum;
};
const int llinf = 4e18;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
struct str {
    int len; int zeros;
    str(){
        len = 0; zeros = 0;
    }
};
struct cmp {    // 在有 template 的資結使用
    bool operator()(const str &a, const str &b) const {
        return a.zeros < b.zeros;
    }
    // sort, bound 不用 struct
    // priority queue 小到大是 > , set 是 <
    // set 不能 = , multiset 要 = 
    // 每個元素都要比到，不然會不見
};
void anna_move(priority_queue<str, vector<str>, cmp> &pq){
    str a = pq.top(); pq.pop();
    a.len -= a.zeros;
    a.zeros = 0;
    pq.push(a);
}
void sasha_move(priority_queue<str, vector<str>, cmp> &pq){
    str a = pq.top(); pq.pop();
    str b = pq.top(); pq.pop();
    str c;
    c.len = a.len + b.len;
    c.zeros = b.zeros;
    pq.push(c);
}
void solve(){
    int n, m; cin >> n >> m;
    priority_queue<str, vector<str>, cmp> pq;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int zeros = 0;
        int siz = s.size();
        for(int i = siz - 1; i >= 0; i--) {
            if(s[i] == '0') zeros++;
            else break;
        }
        str a;
        a.len = s.size(); a.zeros = zeros;
        pq.push(a);
    }
    anna_move(pq);
    // cout << pq.top().len << " " << pq.top().zeros << "\n";
    while(pq.size() >= 2){
        sasha_move(pq);
        anna_move(pq);
    // cout << pq.top().len << " " << pq.top().zeros << "\n";
    }
    str ans = pq.top();
    // cout << ans.len << " " << ans.zeros << endl;
    if(ans.len <= m){
        cout << "Anna\n";
    }
    else cout << "Sasha\n";
}
signed main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}