#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    if (n < 3) {
        cout << stoll(s) << "\n";
        return;
    }

    if (s.find('0') != string::npos) {
        if (s.size() == 3 && s[1] != '0' || s.size() > 3) {
            cout << 0 << "\n";
        } else {
            int a = stoi(string(1, s[0]));
            int b = stoi(string(s.begin() + 1, s.end()));
            cout << min(a + b, a * b) << "\n";
        }
        return;
    }

    int mn = 1e9; int pos = 0;
    // 選開頭 1，後面最好不是 1，否則取 min
    for (int i = 0; i < n - 1; i++) {
        int x = stoi(string(s.begin() + i, s.begin() + i + 2));
        if (mn == 1e9) {
            mn = x;
            pos = i;
            continue;
        }
        if (x / 10 == 1) {
            if (mn / 10 != 1) {
                mn = x;
                pos = i;
            } else if (mn == 11) {
                mn = x;
                pos = i;
            } else if (mn > x) {
                mn = x;
                pos = i;
            }
        }
        else if (x % 10 == 1) {
            if (mn % 10 == 1) {
                if (mn > x) {
                    mn = x;
                    pos = i;
                }
            }
        }
        else {
            if (mn > x) {
                mn = x;
                pos = i;
            }
        }
        
    }
    ll ans = 0, tmp = -1;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (i == pos) {
            if (tmp == -1) {
                tmp = mn;
            } else {
                // tmp = min(tmp + mn, tmp * mn);
                if (tmp + mn < tmp * mn) {
                    ans += tmp;
                    flag = 1;
                    tmp = mn;
                } else {
                    tmp *= mn;
                }
            }
            i++;
        }
        else {
            if (tmp == -1) {
                tmp = s[i] - '0';
            } else {
                // tmp = min(tmp + s[i] - '0', tmp * (s[i] - '0'));
                if (tmp + s[i] - '0' < tmp * (s[i] - '0')) {
                    ans += tmp;
                    flag = 1;
                    tmp = s[i] - '0';
                } else {
                    tmp *= (s[i] - '0');
                }
            }
        }
    }

    if (tmp != -1 && flag) {
        ans = min(ans + tmp, ans * tmp);
    } else {
        ans = tmp;
    }
    
    cout << ans << "\n";

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