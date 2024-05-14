#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int> 
#define endl "\n"
#define int long long
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using pbds_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int llinf = 4e18;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

#include <bits/stdc++.h>
using namespace std;
struct KMP {
    string sub;
    vector<int> failure;
    KMP(string sub) {
        this->sub = sub;
        failure.resize(sub.size(), -1);
        buildFailFunction();
    }
    void buildFailFunction() {
        for(int i = 1; i < sub.size(); i++) {
            int now = failure[i - 1];
            while(now != -1 && sub[now + 1] != sub[i]) now = failure[now];
            if (sub[now + 1] == sub[i]) failure[i] = now + 1;
        }
    }
    vector<int> KMPmatching(string &s) {
        vector<int> match;
        for(int i = 0, now = -1; i < s.size(); i++) {
            // now is the compare sucessed length -1
            while (s[i] != sub[now + 1] && now != -1) now = failure[now];
            // f stores if comparison fail, move to where
            if (s[i] == sub[now + 1]) now++;
            if (now + 1 == sub.size()) {
                match.push_back(i - now);
                now = failure[now];
            }
        }
        return match;
    }
};

void solve() {
    int sz, a, b; cin >> sz >> a >> b;
    string s; cin >> s;
    int l = 1, r = sz / a;
    int mx = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        KMP kmp(s.substr(0, m));
        vector<int> match = kmp.KMPmatching(s);
        int x = match.size();
        for (int i = 0; i < match.size() - 1; i++) {
            if (match[i + 1] - match[i] < m) {
                x--;
                match[i + 1] = match[i];
            }
        }
        if (x >= a) {
            mx = max(mx, m);
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << mx << "\n";
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