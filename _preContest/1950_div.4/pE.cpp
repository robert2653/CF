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

vector<int> is_prime(2e5 + 1, 1);
void solve() {
    int n; cin >> n;
    int x = n;
    map<int, int> comp;
    string s; cin >> s;
    while (is_prime[x] != 1) {
        comp[is_prime[x]]++;
        x /= is_prime[x];
    }
    if (x != 1) comp[x]++;
    vector<int> fac;
    vector<pair<int, int>> vcomp;
    for (auto [i, j] : comp) vcomp.push_back({i, j});

    auto dfs = [&](auto self, int now, int n) -> void {
        if (n == vcomp.size()) {
            fac.push_back(now);
            return;
        }
        self(self, now, n + 1);
        for (int i = 0; i < vcomp[n].second; i++) {
            now *= vcomp[n].first ;
            self(self, now, n + 1);
        }
    };
    dfs(dfs, 1, 0);
    sort(all(fac));
    for (auto i : fac) {
        int done = 1;
        for (int j = 0; j < i; j++) {
            char c = s[j];
            for (int k = 0; k < n / i; k++) {
                if (s[i * k + j] != c) {
                    done--;
                    if (done < 0) break;
                }
            }
            if (done < 0) break;
        }
        if (done < 0) {
            done = 1;
            for (int j = 0; j < i; j++) {
                char c = s[j + i];
                for (int k = 0; k < n / i; k++) {
                    if (s[i * k + j] != c) {
                        done--;
                        if (done < 0) break;
                    }
                }
                if (done < 0) break;
            }
        }
        if (done >= 0) {
            cout << i << "\n";
            return;
        }
    }
}

signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    // 1 代表是質數，非 1 不是
    for (int i = 2; i <= 480; i++) {
        if (is_prime[i] == 1) {
            for (int j = i + i; j <= 200000; j += i) {
                is_prime[j] = i;
            }
        }
    }
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}