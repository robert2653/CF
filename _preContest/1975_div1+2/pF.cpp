#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bitset<21> decode(int x, int n) {
    bitset<21> b;
    for (int i = 0; i < n; ++i) {
        if (x & (1 << i)) {
            b[i] = 1;
        }
    }
    return b;
}

void solve() {
    int n; cin >> n;
    
    int size = (1 << n) - 1;
    vector<bitset<21>> v(size + 1);
    
    for (int i = 1; i <= size; ++i) {
        int x; cin >> x;
        v[i] = decode(x, n + 1);
    }

    vector<int> ans;

    for (int S = 1; S < (1 << n); S++) {
        bool ok = true;
        bitset<21> bS = S;
        
        for (int T = 1; T < (1 << n); T++) {
            bitset<21> bT = T;
            int cnt = (bS & bT).count();
            if (!v[T][cnt]) {
                ok = false;
                break;
            }
        }
        
        if (ok) {
            ans.push_back(S);
        }
    }
    
    cout << ans.size() << "\n";
    for (auto S : ans) {
        cout << S << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}