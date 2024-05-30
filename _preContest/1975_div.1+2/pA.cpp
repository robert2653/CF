#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ok = 1;
    int s = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            s = i;
            ok = 0;
            break;
        }
    }
    if (ok) { cout << "Yes\n"; return; }
    else {
        ok = 1;
        for (int l = s, r = (s + 1) % n, cnt = 1; cnt < n; (l += 1) %= n, (r += 1) %= n, cnt++) {
            if (a[l] > a[r]) {
                ok = 0;
                break;
            }
        }
        if (!ok) cout << "No\n";
        else cout << "Yes\n";
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