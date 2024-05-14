#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define N 2000010
ll MOD = 998244353;
 
ll f1[N + 1], f2[N + 1];
 
ll inv(ll a, ll b) { return 1 < a ? b - inv(b % a, a) * b / a : 1; } // inv a mod b
 
ll choose(ll n, ll k) { return f1[n] * f2[k] % MOD * f2[n - k] % MOD; } // n choose k
 
void combo() {
    f1[0] = 1;
    f2[0] = 1;
    for (int i = 1; i <= N; i++) {
        f1[i] = f1[i - 1] * i % MOD;
        f2[i] = inv(f1[i], MOD);
    }
}
 
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res *= a;
        a *= a;
        res %= MOD;
        a %= MOD;
        b >>= 1;
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    combo();
    ll n, q;
    cin >> n >> q;
    ll a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    ll prefix1[n + 1] = {};
    ll prefix2[n + 1] = {};
    for (int i = 0; i < n; i++) {
        prefix1[i + 1] = prefix1[i] + a[i];
        prefix2[i + 1] = prefix2[i] + b[i];
    }
    ll k = prefix2[n];
    ll prefix3[k + 2] = {};
    for (int i = 1; i <= k + 1; i++) {
        prefix3[i] = prefix3[i - 1];
        prefix3[i] += binpow(inv(2, MOD), k) * choose(k, i - 1) % MOD;
        prefix3[i] %= MOD;
    }
    while (q--) {
        ll l, r;
        cin >> l >> r;
        l -= 1;
        r -= 1;
        ll a1 = prefix1[r + 1] - prefix1[l];
        ll a2 = prefix1[n] - a1;
        ll b1 = prefix2[r + 1] - prefix2[l];
        ll b2 = prefix2[n] - b1;
        if (a2 + b2 < a1) {
            cout << 1 << "\n";
            continue;
        }
        if (a1 + b1 <= a2) {
            cout << 0 << "\n";
            continue;
        }
        cout << (1 - prefix3[0ll, a2 - a1 + b2 + 1] + MOD) % MOD << "\n";
    }
}