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
void stradd(deque<char> &ans, string s, int start) {
    int carry = 0;
    for (int i = 0; i < s.size() || carry; i++) {
        while (ans.size() < start + i + 1) ans.push_back('0');
        int x = 0;
        if(s.size() > i) x += s[i] - '0';
        x += ans[start + i] - '0';
        x += carry;
        carry = x / 10;
        ans[start + i] = x % 10 + '0';
    }
}
void solve(){
    int n; cin >> n;
    deque<char> num;
    bool ok = false;
    int pref = 0;
    for(int i = 0; i < n; i++) {
        char c; cin >> c;
        if (c == '0' && !ok) continue;
        else {
            ok = 1;
            num.push_back(c);
            pref += c - '0';
        }
    }
    deque<char> ans;
    reverse(all(num));
    int now = 0;
    while (pref) {
        string tmp = to_string(pref);
        reverse(all(tmp));
        stradd(ans, tmp, now);
        pref -= num.front() - '0';
        num.pop_front();
        // cout << tmp << " ";
        now++;
    }
    reverse(all(ans));
    for(char c : ans) cout << c;
    cout << endl;
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