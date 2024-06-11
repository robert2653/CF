#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    // -100 200 -10000
    vector<ll> pos_pref(n + 1), neg_pref(n + 1);
    // pos max, neg min
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        pos_pref[i + 1] = max(llabs(pos_pref[i] + x), llabs(neg_pref[i] + x));
        neg_pref[i + 1] = min(neg_pref[i] + x, pos_pref[i] + x);
    }
    // for (auto i : pos_pref) cout << i << " "; cout << "\n";
    // for (auto i : neg_pref) cout << i << " "; cout << "\n";
    cout << max(pos_pref[n], llabs(neg_pref[n])) << "\n";
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