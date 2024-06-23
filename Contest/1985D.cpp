#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> g(n);
    int ok = 0;
    int mx = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++) {
        int start = 0;
        cin >> g[i];
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '#') {
                cnt++;
                if (!start)
                    start = j + 1;
            }
        }
        if (cnt) {
            ok = 1;
        }
        if (ok) {
            if (cnt > mx) {
                mx = cnt;
                x = i;
                y = start + cnt / 2;
            }
        }
    }
    cout << x + 1  << " " << y << "\n";
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