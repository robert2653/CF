#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll inf = 4e18;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + m + 1), b(n + m + 1);
    vector<ll> prefa(n + m + 2), prefb(n + m + 2);
    vector<array<ll, 3>> pp(n + m + 2), tp(n + m + 2);
    pp.push_back({inf, inf, inf});
    tp.push_back({inf, inf, inf});
    for (int i = 0; i <= n + m; i++) {
        cin >> a[i];
        prefa[i + 1] = prefa[i] + a[i];
    }
    for (int i = 0; i <= n + m; i++) {
        cin >> b[i];
        prefb[i + 1] = prefb[i] + b[i];

        pp[i + 1] = pp[i];
        tp[i + 1] = tp[i];
        if (a[i] > b[i]) {
            pp[i + 1][0]++;
            pp[i + 1][1] += a[i];
            pp[i + 1][2] = i + 1;
        }
        else {
            tp[i + 1][0]++;
            tp[i + 1][1] += b[i];
            tp[i + 1][2] = i + 1;
        }
    }
    for (int i = 0; i <= n + m; i++) {
        ll ans = 0;
        if (a[i] > b[i]) { // n + 1
            auto itp = lower_bound(pp.begin() + 1, pp.end(), array<ll, 3>{n + 1, 0, 0});
            auto itt = lower_bound(tp.begin() + 1, tp.end(), array<ll, 3>{m, 0, 0});
            ll p1 = (*itp)[2], p2 = (*itt)[2];
            if (p1 > p2) {
                ans = pp[p2][1] + tp[p2][1] + prefa[n + m + 1] - prefa[p2] - (i + 1 <= p2 ? 0 : a[i]) - (i + 1 <= p2 ? b[i] : 0);
            }
            else {
                ans = pp[p1][1] + tp[p1][1] + prefb[n + m + 1] - prefb[p1] - (i + 1 <= p1 ? 0 : b[i]) - (i + 1 <= p1 ? a[i] : 0);
            }
        }
        else {
            auto itp = lower_bound(pp.begin() + 1, pp.end(), array<ll, 3>{n, 0, 0});
            auto itt = lower_bound(tp.begin() + 1, tp.end(), array<ll, 3>{m + 1, 0, 0});
            ll p1 = (*itp)[2], p2 = (*itt)[2];
            if (p1 > p2) {
                ans = pp[p2][1] + tp[p2][1] + prefa[n + m + 1] - prefa[p2] - (i + 1 <= p2 ? 0 : a[i]) - (i + 1 <= p2 ? b[i] : 0);
            }
            else {
                ans = pp[p1][1] + tp[p1][1] + prefb[n + m + 1] - prefb[p1] - (i + 1 <= p1 ? 0 : b[i]) - (i + 1 <= p1 ? a[i] : 0);
            }
        }
        cout << ans << " \n"[i == n + m];
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