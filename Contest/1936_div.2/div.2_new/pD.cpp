#include <bits/stdc++.h>
 
using i64 = long long;
 
constexpr i64 inf = 1E18;
 
void solve() {
    int n, c;
    std::cin >> n >> c;
    
    i64 ans = 1LL * (c + 1) * (c + 2) / 2;
    
    std::vector<int> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    for (int i = 0; i < n; i++) {
        ans -= s[i] / 2 + 1;
        ans -= c - s[i] + 1;
    }
    
    int cnt[2] {};
    for (int i = 0; i < n; i++) {
        cnt[s[i] % 2]++;
    }
    for (int i = 0; i < 2; i++) {
        ans += 1LL * cnt[i] * (cnt[i] + 1) / 2;
    }
    std::cout << ans << "\n";
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}