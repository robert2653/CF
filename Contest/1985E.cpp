#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    // a * b * c = k
    // ans = (x - a + 1) * (y - b + 1) * (z - c + 1)
    vector<ll> a(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    ll k; cin >> k;
    ll now = 1, mx = 0;
    ll x = k;
    for (int i = 1; i <= a[0]; i++) {
        now = 1;
        x = k;
        if (x % i == 0 && x / i <= a[1] * a[2]) {
            now *= a[0] - i + 1;
            x /= i;
            for (int j = 1; j <= a[1]; j++) {
                if (x % j == 0 && x / j <= a[2]) {
                    now *= a[1] - j + 1;
                    x /= j;
                    for (int l = x; l <= a[2]; l++) {
                        if (x % l == 0) {
                            mx = max(mx, now * (a[2] - l + 1));
                        }
                    }
                    now /= a[1] - j + 1;
                    x *= j;
                }
            }
            now /= a[0] - i + 1;
            x *= i;
        }
    }
    cout << mx << "\n";

    
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