#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll x; cin >> x;
    // 0, 5 5
    // 1, 5 6
    // 2, 5 7
    // 3, 5 8
    // 4, 5 9
    // 5, 6 9
    // 6, 7 9
    // 7, 8 9
    // 8, 9 9
    // 9, 9 9 
    while (x > 0) {
        if (x % 10 == 9) {
            cout << "NO\n";
            return;
        }
        x /= 10;
        x--;
        if (x > 0 && x < 10) {
            cout << "NO\n";
            return;
        }
        // cout << x << " ";
    }
    cout << "YES\n";
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