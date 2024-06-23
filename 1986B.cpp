#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> fx{0, 0, -1, 1};
    vector<int> fy{1, -1, 0, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int mx = 0;
            int ok = 1;
            for (int k = 0; k < 4; k++) {
                if (i + fx[k] >= 0 && i + fx[k] < n && j + fy[k] >= 0 && j + fy[k] < m) {
                    if (a[i][j] > a[i + fx[k]][j + fy[k]]) {
                        mx = max(mx, a[i + fx[k]][j + fy[k]]);
                    } else {
                        ok = 0;
                    }
                }
            }
            if (ok) {
                a[i][j] = mx;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " \n"[j == m - 1];
        }
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