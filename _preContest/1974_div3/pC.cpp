#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    vector<array<int, 3>> compose;
    for (int i = 0; i < n - 2; i++) {
        compose.push_back({a[i], a[i + 1], a[i + 2]});
    }
    map<pair<int, int>, map<int, int>> mp;
    for (auto [i, j, k] : compose) {
        mp[{i, j}][k]++;
    }
    for (auto [i, j] : mp) {
        int cnt = 0;
        for (auto [k, v] : j) {
            ans += cnt * v;
            cnt += v;
        }
    }
    mp.clear();
    for (auto [i, j, k] : compose) {
        mp[{i, k}][j]++;
    }
    for (auto [i, j] : mp) {
        int cnt = 0;
        for (auto [k, v] : j) {
            ans += cnt * v;
            cnt += v;
        }
    }
    mp.clear();
    for (auto [i, j, k] : compose) {
        mp[{j, k}][i]++;
    }
    for (auto [i, j] : mp) {
        int cnt = 0;
        for (auto [k, v] : j) {
            ans += cnt * v;
            cnt += v;
        }
    }
    mp.clear();
    cout << ans << "\n";

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}