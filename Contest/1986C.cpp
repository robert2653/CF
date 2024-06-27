#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int m; cin >> m;
    string s; cin >> s;
    vector<int> a(m);
    deque<char> dq(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> dq[i];
    }

    sort(a.begin(), a.end());
    sort(dq.begin(), dq.end());

    int pre = a[0];
    for (int i = 0; i < m;) {
        int cnt = 0;
        while (i < m && a[i] == pre) {
            i++;
            cnt++;
        }

        for (int j = 0; j < cnt - 1; j++) {
            dq.pop_back();
        }
        s[pre - 1] = dq.front();
        dq.pop_front();

        if (i < m) {
            pre = a[i];
        }
    }

    cout << s << "\n";
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