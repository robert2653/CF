#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define int long long
typedef pair<int, int> pii;
typedef struct {
    int from; int to;
    int weight;
} edge;
typedef struct {
    int sum;
} Node;
const int llinf = 4e18;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
struct KMP {
    string sub;
    vector<int> failure;
    KMP(string &sub) {
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
void solve(){
    string s; cin >> s;
    string sub = "happiness";
    KMP kmp(sub);
    vector<int> tmp = kmp.KMPmatching(s);
    if(tmp.size() > 2){
        cout << "NO\n";
    }
    else if(tmp.size() == 2){
        cout << "YES\n";
        cout << tmp[0] + 1 << " " << tmp[1] + 2 << endl;
    }
    else if(tmp.size() == 1){
        cout << "YES\n";
        cout << tmp[0] + 1 << " " << tmp[0] + 2 << endl;
    }
    else {
        cout << "YES\n";
        swap(s[0], s[1]);
        tmp = kmp.KMPmatching(s);
        if(tmp.size() == 0){
            cout << "1 2\n";
        }
        else {
            cout << "1 3\n";
        }
    }

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}