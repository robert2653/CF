#include <bits/stdc++.h>
using namespace std;

// 求最大 XOR 區間
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
        a[i + 1] ^= a[i];
    }
    // sort(a.begin(), a.end());
    // a.erase(unique(a.begin(), a.end()), a.end());
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < i; j++) {
            ans = max(ans, a[i] ^ a[j]);
        }
    }
    cout << ans << "\n";
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}