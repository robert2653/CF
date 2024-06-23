#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct TwoDimensionBIT {
    int nx, ny;
    vector<vector<int>> bit;
    TwoDimensionBIT(int x, int y) {
        nx = x; ny = y;
        bit.resize(x + 1, vector<int>(y + 1, 0));
    }
    void modify(int x, int y, int mod) {
        for (; x <= nx; x += x & -x) {
            for (int tmp = y; tmp <= ny; tmp += tmp & -tmp) {
                bit[x][tmp] += mod;
            }
        }
    }
    int query(int r1, int r2) {
        int ans = 0;
        for (; r1; r1 -= r1 & -r1) {
            for (int tmp = r2; tmp; tmp -= tmp & -tmp) {
                ans += bit[r1][tmp];
            }
        }
        return ans;
    }
    int query(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    TwoDimensionBIT bit(n + 5, m + 5);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '#') {
                bit.modify(i + 1, j + 1, 1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            int x = bit.query(1, 1, 2, m) + m - bit.query(1, 1, 1, m);
            ans = max(ans, x);
        } else if (i == n) {
            int x = bit.query(i - 1, 1, n, m) + m - bit.query(n, 1, n, m);
            ans = max(ans, x);
        } else {
            int x = bit.query(i - 1, 1, i + 1, m) + m - bit.query(i, 1, i, m);
            ans = max(ans, x);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (i == 1) {
            int x = bit.query(1, 1, n, 2) + n - bit.query(1, 1, n, 1);
            ans = max(ans, x);
        } else if (i == m) {
            int x = bit.query(1, m - 1, n, m) + n - bit.query(1, m, n, m);
            ans = max(ans, x);
        } else {
            int x = bit.query(1, i - 1, n, i + 1) + n - bit.query(1, i, n, i);
            ans = max(ans, x);
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