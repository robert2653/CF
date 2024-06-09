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
bool check_pre(vector<int> &pref, int x, int l, int r) {
    if (pref[r] - pref[l - 1] > x) return true;
    else return false;
}
bool check_suf(vector<int> &suf, int x, int l, int r) {
    if (suf[l] - suf[r + 1] > x) return true;
    else return false;
}
void solve(){
    int n; cin >> n;
    vector<int> pref(n + 1, 0);
    vector<int> suf(n + 2, 0);
    vector<int> num(n + 2, 0);
    int remain = 0;
    for (int i = 1; i <= n; i++) {   // ind 1
        cin >> num[i];
        if (num[i] == num[i - 1]) {
            remain += num[i];
            pref[i] = pref[i - 1];
        }
        else {
            pref[i] = pref[i - 1] + num[i] + remain;
            remain = 0;
        }
        cout << pref[i] << " ";
    }   
    remain = 0;
    for (int i = n; i >= 1; i--) {  // ind 1
        if (num[i] == num[i + 1]) {
            remain += num[i];
            suf[i] = suf[i + 1];
        }
        else {
            suf[i] = suf[i + 1] + num[i] + remain;
            remain = 0;
        }
    }
    // for (auto i : pref) cout << i << " ";
    // cout << "\n";
    // for (auto i : suf) cout << i << " ";
    // cout << "\n";
    // vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        bool ok = 0;
        int ans = inf;
        int x = num[i];
        int l = i + 1, r = n;
        while (l <= r) {
            int m = (l + r) / 2;
            if (check_pre(pref, x, i + 1, m)) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        if (l > i && l <= n) {
            ok = 1;
            ans = min(ans, l - i);
        }

        l = 1, r = i - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (check_suf(suf, x, m, i - 1)) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }   
        if (r >= 1 && r < i) {
            ok = 1;
            ans = min(ans, i - r);
        }
        if (ok) cout << ans << " ";
        else cout << -1 << " ";
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