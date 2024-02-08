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
using pbds_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
template <class Node>
struct Seg {
    int n;
    vector<Node> tree;
    template <typename T>
    Seg (vector<T> init_){
        n = init_.size() - 1;
        tree.resize(4 * n);
        function <void(int, int, int)> build = [&](int now, int l, int r) {
            if (l == r) {
                tree[now] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(now << 1, l, m);
            build((now << 1) + 1, m + 1, r);
            pull(now);
        };
        build(1, 1, n);
    }
    Node query(int l, int r, int ql, int qr, int now){
        int m = (l + r) >> 1;
        if(qr < l || ql > r){
// ------------------------out of range, return what-------------------------------
            return Node();
// --------------------------------------------------------------------------------
        }
        if(ql <= l && r <= qr){
            return tree[now];
        }
	    return query(l, m, ql, qr, now << 1) + query(m + 1, r, ql, qr, (now << 1) + 1);
    }
    Node query(int l, int r) { return query(1, n, l, r, 1); }
    void pull(int now){
        tree[now] = tree[now << 1] + tree[(now << 1) + 1];
    }
};
// ------------------------define structure and info plus------------------------
struct Node {
    bool done;
    int l, r;
    set<int> rec;
    Node(){
        done = false;
        l = 0;
        r = 0;
        rec.clear();
    }
};
Node operator+(const Node &a, const Node &b) {
    Node n;
    if(a.done){
        n = a;
    }
    else if(b.done){
        n = b;
    }
    else {
        if(!a.rec.empty() && !b.rec.empty() && *a.rec.begin() != *b.rec.begin()){
            n.l = a.l;
            n.r = b.l;
            n.done = true;
        }
        else {
            n.done = false;
            n.l = max(a.l, b.l);
            if(!a.rec.empty()) n.rec = a.rec;
            else n.rec = b.rec;
        }
    }
    return n;
    // use lc、rc to undate now
    // tree[now].sum = tree[lc].sum + tree[rc].sum;
    // tree[now].prefix = max(tree[lc].sum+tree[rc].prefix, tree[lc].prefix);
    // tree[now].suffix = max(tree[lc].suffix+tree[rc].sum, tree[rc].suffix);
    // tree[now].middle_max = max(max(tree[lc].middle_max, tree[rc].middle_max), tree[lc].suffix+tree[rc].prefix);
    // tree[now].middle_max = max(max(tree[now].middle_max, tree[now].prefix), tree[now].suffix);
}
void solve(){
    int n; cin >> n;
    vector<Node> v(n + 1, Node());
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        v[i].rec.insert(x);
        v[i].l = i;
    }
    Seg<Node> seg(v);
    int q; cin >> q;
    for(int i = 1; i <= q; i++){
        int l, r; cin >> l >> r;
        Node ans = seg.query(l, r);
        if(ans.done){
            cout << ans.l << " " << ans.r << "\n";
        }
        else {
            cout << -1 << " " << -1 << "\n";
        }
    }
    cout << "\n";
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