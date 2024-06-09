#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int N = 2e5 + 1;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<ll> p(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p[i + 1] = p[i] + a[i];
    }

    ll ans = 0;
    bitset<N> f;
    f[1] = 1;
    for (int i = 0; i < n; i++) { // 開了 i 個箱子的總和，扣 i 回去、用 prefix 求和
        f |= f << a[i];
        if (f[i + 1]) {
            f[i + 1] = 0;
            ans = max(ans, p[i + 1] - i);
        }
    }
    for (int i = n; i <= 2 * n; i++) {
        if (f[i]) {
            ans = max(ans, p[n] - i + 1);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}