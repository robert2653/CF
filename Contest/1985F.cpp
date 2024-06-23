#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int h, n; cin >> h >> n;
    vector<ll> a(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    ll l = 0, r = 40000000000 - 1;
    while (l <= r) {
        ll m = (l + r) / 2;
        ll x = 0;
        for (int i = 0; i < n; i++) {
            x += a[i] * (m / c[i] + 1);
            if (x >= h) break;
        }
        if (x >= h) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << l + 1 << "\n";
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