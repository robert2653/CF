#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x = a[0];
    int ok = 0;
    for (auto i : a) {
        if (i != x) {
            ok = 1;
            break;
        }
    }
    if (!ok) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (a[0] == a[1]) {
        cout << "B";
        for (int i = 1; i < n; i++) cout << "R";
    } else {
        for (int i = 1; i < n; i++) cout << "R";
        cout << "B";
    }
    cout << "\n";
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