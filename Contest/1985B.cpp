#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int ans = 0;
    int mx = 0;
    for (int i = 2; i <= n; i++) {
        int y = n / i * i;
        int x = (i + y) * ((y - i) / i + 1) / 2;
        if (x > mx) {
            ans = i;
            mx = x;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}