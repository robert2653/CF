#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1);
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll pref = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        pq.push(a[i]);
        pref += a[i];
        if (pref - pq.top() == pq.top()) {
            ans++;
        }
        // cout << pref << " " << pq.top() << ", ";
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