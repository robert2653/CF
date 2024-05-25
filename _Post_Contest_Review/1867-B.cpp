#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    int n; cin >> n;
    
    string s; cin >> s;
    
    int l = 0, r = 0; // 可能的數量區間
    for (int i = 0; i < n - 1 - i; i++) {
        if (s[i] == s[n - 1 - i]) {
            r += 2; // 可以都塞 1，可以都塞 0
        } else {
            l++, r++; // 一定要塞一個 1
        }
    }
    
    string ans(n + 1, '0');
    for (int i = l; i <= r; i += 2) {
        ans[i] = '1';
        if (n % 2 == 1) { // 中間的可以隨便塞
            ans[i + 1] = '1';
        }
    }
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}