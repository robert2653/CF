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
};

void solve() {
    int n, m, k; cin >> n >> m >> k;
    ll x = 0, y = 0;
    vector g(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }

    TwoDimensionBIT bit(n, m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            if (c == '0') {
                x += g[i][j];
                bit.modify(i, j, 1);
            }
            else {
                y += g[i][j];
                bit.modify(i, j, -1);
            }
        }
    }

    ll gcd = 0;
    for (int i = 1; i + k - 1 <= n; i++) {
        for (int j = 1; j + k - 1 <= m; j++) {
            ll x = bit.query(i + k - 1, j + k - 1) - bit.query(i + k - 1, j - 1) - bit.query(i - 1, j + k - 1) + bit.query(i - 1, j - 1);
            if (x) gcd = std::gcd(x, gcd);
        }
    }

    if (gcd != 0 && llabs(x - y) % gcd == 0) {
        cout << "YES\n";
    } else if (x == y) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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