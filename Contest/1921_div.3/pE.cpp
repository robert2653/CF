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
// odd => Alice 靠近 Bob
// even => Alice 遠離 Bob
void solve(){
    int h, w, aliceH, aliceW, bobH, bobW;
    cin >> h >> w >> aliceH >> aliceW >> bobH >> bobW;
    if(aliceH >= bobH) {
        cout << "Draw\n";
        return;
    }
    int disH = bobH - aliceH;
    if(disH & 1){
        if(aliceW <= bobW) {
            aliceW = min(w, aliceW + disH / 2 + 1);
            bobW = min(w, bobW + disH / 2);
            cout << (aliceW >= bobW ? "Alice" : "Draw") << endl;
        }
        else {
            aliceW = max(1LL, aliceW - disH / 2 - 1);
            bobW = max(1LL, bobW - disH / 2);
            cout << (aliceW <= bobW ? "Alice" : "Draw") << endl;
        }
    }
    else {
        if(aliceW <= bobW) {
            aliceW = max(1LL, aliceW - disH / 2);
            bobW = max(1LL, bobW - disH / 2);
            cout << (aliceW >= bobW ? "Bob" : "Draw") << endl;
        }
        else {
            aliceW = min(w, aliceW + disH / 2);
            bobW = min(w, bobW + disH / 2);
            cout << (aliceW <= bobW ? "Bob" : "Draw") << endl;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}