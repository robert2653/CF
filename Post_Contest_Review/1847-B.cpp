#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
const int mod = 1e9 + 7;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int all = ~0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        all &= a[i];
    }
    if (all != 0) {
        cout << 1 << "\n";
        return;
    }
    int now = ~0;
    int ans = 0;
    for (auto i : a) {
        now &= i;
        if (now == 0) {
            ans++;
            now = ~0;
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