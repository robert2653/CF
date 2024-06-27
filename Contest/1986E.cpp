#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    ll ans = 0;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = a[i].first % k;
        a[i].first = a[i].first / k;
    }
    map<int, deque<int>> mp;
    for (auto [i, j] : a) {
        mp[j].push_back(i);
    }

    int flag = 0;
    if (n & 1) flag = 1;
    for (auto [i, v] : mp) {
        sort(v.begin(), v.end());
        if (v.size() & 1) {
            if (!flag) { cout << -1 << "\n"; return; }
            flag = 0;
            if (v.size() == 1) continue;
            for (int j = v.size() - 1; j > 0; j--) {
                v[j] -= v[j - 1];
            }
            ll mn = 0;
            for (int j = 1; j < v.size(); j += 2) {
                mn += v[j + 1];
            }
            ll now = mn;
            for (int j = 1; j < v.size(); j += 2) {
                now += v[j];
                now -= v[j + 1];
                mn = min(mn, now);
            }
            ans += mn;
        }
        else {
            for (int j = 0; j < v.size(); j += 2) {
                ans += v[j + 1] - v[j];
            }
        }
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