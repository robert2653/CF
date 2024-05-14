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



void solve(vector<int> &v) {
    int n; cin >> n;
    for (auto i : v) {
        if (i == 1) continue;
        while (n % i == 0) {
            n /= i;
        }
        if (i == 1) break;
    }
    if (n == 1) {
        cout << "YES\n";
    }
    else cout << "NO\n";
}

signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    vector<int> v;
    string tmp = "1";
    auto dfs = [&](auto self, int n, string now) -> void {
        v.push_back(stoll(now));
        if (n == 5) {
            return;
        }
        now.push_back('1');
        self(self, n + 1, now);
        now.pop_back();
        now.push_back('0');
        self(self, n + 1, now);

    };
    dfs(dfs, 1, tmp);
    sort(all(v), greater<int>());
    // for (auto i : v) cout << i << " ";
    int t = 1;
    cin >> t;
    while (t--) {
        solve(v);
    }
}