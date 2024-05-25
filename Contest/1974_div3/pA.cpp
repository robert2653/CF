#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
const int mod = 1e9 + 7;

void solve() {
    int x, y; cin >> x >> y;
    int ans = (y + 1) / 2;
    int used = y * 4;
    if (ans * 15 - used < x) {
        x -= ans * 15 - used;
        ans += x / 15 + (x % 15 != 0);
    }
    cout << ans << '\n';
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