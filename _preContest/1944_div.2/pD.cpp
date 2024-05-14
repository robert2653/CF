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
const int llinf = 4e18;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

vector<int> manacher(string s) {
    string t = "#";
    for (auto c : s) {
        t += c;
        t += '#';
    }
    int n = t.size();
    vector<int> r(n);
    for (int i = 0, j = 0; i < n; i++) {    // i 是中心, j 是最長回文字串中心
        if (2 * j - i >= 0 && j + r[j] > i) {
            r[i] = min(r[2 * j - i], j + r[j] - i);
        }
        while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {
            r[i] += 1;
        }
        if (i + r[i] > j + r[j]) {
            j = i;
        }
    }
    return r; 
    // # a # b # a #
    // 1 2 1 4 1 2 1
    // index 為奇數代表中心點在字元上(即回文字串長度是奇數)
}

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    // 只要區間內不是全部一樣，所有小於 len 的偶數長度都可以找到非回文
    // 只要區間內不是完全相間，所有小於 len 的奇數長度都可以找到非回文
    // f1 判斷區間內字母是否全部相同，找偶數
    // f2 判斷區間內字母是否全部相間，找奇數
    // 最後 len 項用 manacher 來判斷
    // dp 紀錄最遠可以維持特性的 idx (應該)
    // f1 如果全配對成功: i  i  i  i  i
    // f2 如果全配對成功: i i-1 i i-1 i
    vector<int> f1(n), f2(n);
    for (int i = n - 1; i >= 0; i--) {
        f1[i] = i + 1 < n && s[i] == s[i + 1] ? f1[i + 1] : i;
        f2[i] = i + 2 < n && s[i] == s[i + 2] ? f2[i + 2] : i + 1;   // 默認配對到隔壁的
    }
    vector<int> radius = manacher(s);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        l--; r--;
        int len = r - l + 1, ans = 0;
        if (f1[l] < r) {    // 如果沒有全部一樣
            int mx = len % 2 == 0 ? len - 2 : len - 1;  // mx 是偶數
            ans += 1LL * (mx / 2) * (mx + 2) / 2;   // 偶數項, 高 * (上底 + 下底) / 2
        }
        if (f2[l] < r || f2[l + 1] < r) { // 如果沒有全部相間
            // 前面判奇數，後面判偶數
            int mx = len % 2 == 0 ? len - 1 : len - 2;  // mx 是奇數
            ans += 1LL * ((mx - 1) / 2) * (mx + 3) / 2; // 從 3 開始加
        }
        if (radius[l + r + 1] <= len) {
            ans += len;
        }
        cout << ans << "\n";
    }
}
signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}