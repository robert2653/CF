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

void solve() {
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    pb--; ps--;
    vector<int> p(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> bscore, sscore;
    int x = 0, y = 0;
    for (int i = 0; i < n && k > 0; i++) {
        bscore.push_back(x + k * v[pb]);
        sscore.push_back(y + k * v[ps]);
        k--;
        x += v[pb];
        y += v[ps];
        pb = p[pb];
        ps = p[ps];
    }
    int ans1 = *max_element(all(bscore));
    int ans2 = *max_element(all(sscore));
    if (ans1 == ans2) cout << "Draw\n";
    else if (ans1 > ans2) cout << "Bodya\n";
    else cout << "Sasha\n";
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