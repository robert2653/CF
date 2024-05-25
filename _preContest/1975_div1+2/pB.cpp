#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int x = a[0];
    int y = a[0];
    for (auto i : a) {
        if (i % x != 0) {
            y = i;
            break;
        }
    }

    int ok = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] % x == 0 || a[i] % y == 0) continue;
        ok = 0;
    }
    cout << (ok ? "Yes" : "No") << "\n";
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