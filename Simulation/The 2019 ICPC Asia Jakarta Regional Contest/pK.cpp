#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int> 
#define endl "\n"
#define int long long
using namespace std;
const int mod = 1e9 + 7;
template <class Node, class Lazy>
struct LazySeg {
    int n;
    vector<Node> tree;
    vector<Lazy> lazy;
    template <typename T>
    LazySeg (vector<T> init_){
        n = init_.size() - 1;
        tree.resize(4 * n);
        lazy.resize(4 * n);
        function <void(int, int, int)> build = [&](int now, int l, int r) {
            if (l == r) {
            // cout << "now : " << now << " l : " << l << " r : " << r << endl;
                // tree[now] = init_[l];
                if(init_[l] == 'A'){
                    tree[now].LAnsLWeight = 1;
                    tree[now].LAnsRWeight = 1;
                    tree[now].RAnsLWeight = 0;
                    tree[now].RAnsRWeight = 1;
                }
                else {
                    tree[now].LAnsLWeight = 1;
                    tree[now].LAnsRWeight = 0;
                    tree[now].RAnsLWeight = 1;
                    tree[now].RAnsRWeight = 1;
                }
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
// -----------------------out of range, return what--------------------------------
            return {1, 0, 0, 1};
// --------------------------------------------------------------------------------
        }
        push(now, l, r);
        if(ql <= l && r <= qr){
            return tree[now];
        }
	    return query(l, m, ql, qr, now << 1) + query(m + 1, r, ql, qr, (now << 1) + 1);
    }
    Node query(int l, int r) { return query(1, n, l, r, 1); }
    void pull(int now){
        tree[now] = tree[now << 1] + tree[(now << 1) + 1];
    }
    void modify(int l, int r, int ql, int qr, int now, int val){
        int m = (l + r) >> 1;
        if(qr < l || ql > r){
            return;
        }
        if(ql <= l && r <= qr){
// ------------------------------how to modify ?-----------------------------------
            lazy[now].rev ^= 1;
// --------------------------------------------------------------------------------
            return;
        }
        push(now, l, r);
        modify(l, m, ql, qr, now << 1, val);
        modify(m + 1, r, ql, qr, (now << 1) + 1, val);
        push(now << 1, l, m);
        push((now << 1) + 1, m + 1, r);
        pull(now);
    }
    void modify(int l, int r, int val) { modify(1, n, l, r, 1, val); }
    void push(int now, int l, int r){
        apply(now, l, r);
// -----------------------how to push down ?---------------------------------------
        if(l != r){
            if(lazy[now].rev){
                lazy[now << 1].rev ^= 1;
                lazy[(now << 1) + 1].rev ^= 1;
            }
            // lazy[now << 1].rev = lazy[(now << 1) + 1].rev = lazy[now].rev;
        }
// --------------------------------------------------------------------------------
        lazy[now] = Lazy();
    }
    void apply(int now, int l, int r){
        if(lazy[now].rev){
            swap(tree[now].LAnsLWeight, tree[now].RAnsRWeight);
            swap(tree[now].LAnsRWeight, tree[now].RAnsLWeight);
        }
    }
};
// ------------------------define structure and info plus------------------------
struct Node {
    int LAnsLWeight = 0;
    int LAnsRWeight = 0;
    int RAnsLWeight = 0;
    int RAnsRWeight = 0;
};
struct Lazy {
    bool rev = false;
};
Node operator+(const Node &a, const Node &b) {
    Node tmp;
    tmp.LAnsLWeight = (a.LAnsLWeight * b.LAnsLWeight + a.RAnsLWeight * b.LAnsRWeight) % mod;
    tmp.LAnsRWeight = (a.LAnsRWeight * b.LAnsLWeight + a.RAnsRWeight * b.LAnsRWeight) % mod;
    tmp.RAnsLWeight = (a.LAnsLWeight * b.RAnsLWeight + a.RAnsLWeight * b.RAnsRWeight) % mod;
    tmp.RAnsRWeight = (a.LAnsRWeight * b.RAnsLWeight + a.RAnsRWeight * b.RAnsRWeight) % mod;
    return tmp;
}
void solve() {
    int n, q; cin >> n >> q;
    vector<char> s(n + 1);
    for(int i = 1; i <= n; i++) cin >> s[i];
    LazySeg<Node, Lazy> Seg(s);
    for(int i = 0; i < q; i++){
        int op; cin >> op;
        if(op == 1){
            // modify
            int l, r; cin >> l >> r;
            Seg.modify(l, r, 'A');  // A is useless
        }
        else {
            int l, r, a, b; cin >> l >> r >> a >> b;
            // query
            Node ans = Seg.query(l, r);
            cout << (ans.LAnsLWeight * a + ans.LAnsRWeight * b) % mod << " ";
            cout << (ans.RAnsLWeight * a + ans.RAnsRWeight * b) % mod << endl; 
        }
    }
}
signed main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}