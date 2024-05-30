#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ok = 1;
    for (int i = 0; i < n; i++) {
        if (!(('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'z'))) ok = 0;
        if (i < n - 1) {
            if ('a' <= s[i] && s[i] <= 'z' && '0' <= s[i] && s[i] <= '9') ok = 0;
            else if ('0' <= s[i]  && s[i] <= 'z' && s[i] > s[i + 1]) ok = 0;
            else if ('a' <= s[i] && s[i] <= 'z' && s[i] > s[i + 1]) ok = 0;
        }
        if (!ok) break;
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
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