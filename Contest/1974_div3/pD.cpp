#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<char> ans(n, 0);
    map<char, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]].push_back(i);
    }
    if (abs((int)(mp['E'].size() - mp['W'].size())) & 1) {
        cout << "NO\n";
        return;
    }
    if (abs((int)(mp['N'].size() - mp['S'].size())) & 1) {
        cout << "NO\n";
        return;
    }
    int a = 0, b = 0;
    if (mp['E'].size() >= mp['W'].size()) {
        int x = mp['E'].size() - mp['W'].size();
        x >>= 1;
        for (int i = 0; i < x; i++) {
            ans[mp['E'].back()] = 'H';
            mp['E'].pop_back();
            ans[mp['E'].back()] = 'R';
            mp['E'].pop_back();
            a = 1; b = 1;
        }
    }
    else {
        int x = mp['W'].size() - mp['E'].size(); x >>= 1;
        for (int i = 0; i < x; i++) {
            ans[mp['W'].back()] = 'H';
            mp['W'].pop_back();
            ans[mp['W'].back()] = 'R';
            mp['W'].pop_back();
            a = 1; b = 1;
        }
    }
    int turn = 0;
    int x = mp['E'].size();
    for (int i = 0; i < x; i++) {
        ans[mp['E'].back()] = (turn ? 'H' : 'R');
        mp['E'].pop_back();
        ans[mp['W'].back()] = (turn ? 'H' : 'R');
        mp['W'].pop_back();
        turn ^= 1;
        if (turn) a = 1;
        else b = 1;
    }

    if (mp['N'].size() >= mp['S'].size()) {
        int x = mp['N'].size() - mp['S'].size(); x >>= 1;
        for (int i = 0; i < x; i++) {
            ans[mp['N'].back()] = 'H';
            mp['N'].pop_back();
            ans[mp['N'].back()] = 'R';
            mp['N'].pop_back();
            a = 1; b = 1;
        }
    }
    else {
        int x = mp['S'].size() - mp['N'].size(); x >>= 1;
        for (int i = 0; i < x; i++) {
            ans[mp['S'].back()] = 'H';
            mp['S'].pop_back();
            ans[mp['S'].back()] = 'R';
            mp['S'].pop_back();
            a = 1; b = 1;
        }
    }
    turn = 1;
    x = mp['N'].size();
    for (int i = 0; i < x; i++) {
        ans[mp['N'].back()] = (turn ? 'H' : 'R');
        mp['N'].pop_back();
        ans[mp['S'].back()] = (turn ? 'H' : 'R');
        mp['S'].pop_back();
        turn ^= 1;
        if (turn) a = 1;
        else b = 1;
    }
    if (!(a & b)) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << "\n";
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