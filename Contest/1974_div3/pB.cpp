#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<char> v;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        v.push_back(c);
    }
    vector<char> aux = v;
    sort(all(aux));
    aux.erase(unique(all(aux)), aux.end());
    map<char, char> mp;
    int sz = aux.size();
    for (int l = 0, r = sz - 1; l <= r; l++, r--) {
        mp[aux[l]] = aux[r];
        mp[aux[r]] = aux[l];
    }
    for (auto &c : v) c = mp[c];
    for (auto &c : v) cout << c;
    cout << '\n';
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