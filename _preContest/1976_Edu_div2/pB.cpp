#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n + 1);
    int d = 2e9;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        cin >> b[i];
    }
    ll ans = 1;
    int x = b.back();
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            if (a[i] >= x && x >= b[i]) d = 0;
            else if (x > a[i]) d = min(d, x - a[i]);
            else d = min(d, b[i] - x);
        }
        else {
            if (b[i] >= x && x >= a[i]) d = 0;
            else if (x > b[i]) d = min(d, x - b[i]);
            else d = min(d, a[i] - x);
        }
        ans += abs(a[i] - b[i]);
    }
    cout << ans + d << "\n";
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