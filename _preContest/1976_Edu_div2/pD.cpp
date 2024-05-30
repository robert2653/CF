#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    int n = s.size();
    int x = 0;
    ll ans = 0;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        x += s[i] == '(' ? 1 : -1;
        a[x]++;
        int y = (x + 1) / 2 - 1;
        if (y > 0)
            a[y] = 0;
        if (x > 0)
            ans += a[x] - 1;
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