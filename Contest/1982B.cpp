#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll x, y, k;
    cin >> x >> y >> k;
    // 2 2 1 -> 3
    x++; k--;
    while (x % y == 0) x /= y;
    
    // if ((y - x % y) % y <= k) {
        while (x >= y && ((y - x % y) % y) <= k) {
            int minus = (y - x % y) % y;
            x += (y - x % y) % y;
            k -= minus;
            if (minus == 0) {
                x++;
                k--;
            }
            while (x % y == 0) {
                x /= y;
            }
        }
        if (k) {
            x += k % (y - 1);
            if (x >= k) x %= y;
        }
        cout << x << "\n";


    // } else {
    //     cout << x + k << "\n";
    // }
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