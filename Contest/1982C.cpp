#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int x, y; cin >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 0;
    ll sum = 0;
    int ans = 0;
    while (l < n) {
        if (sum > y) {
            sum -= a[l];
            l++;
        }
        else if (sum < x) {
            if (r >= n) break;
            sum += a[r];
            r++;
        }
        if (x <= sum && sum <= y) {
            l = r;
            ans++;
            sum = 0;
        }
    }
    cout << ans + (x <= sum && sum <= y) << "\n";
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