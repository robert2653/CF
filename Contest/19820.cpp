#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int a, b; cin >> a >> b;
    int c, d; cin >> c >> d;
    if (a > b ^ c < d) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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