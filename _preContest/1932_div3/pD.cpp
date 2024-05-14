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
struct edge {
    int from; int to;
    int weight;
};
struct node {
    int sum;
};
const int llinf = 4e18;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
void solve(){
    int n; cin >> n;
    char king; cin >> king;
    vector<int> c, s, d, h;
    for(int i = 0; i < n * 2; i++) {
        char num, type; cin >> num >> type;
        if(type == 'C') c.push_back(num - '0');
        else if(type =='S') s.push_back(num - '0');
        else if(type == 'D') d.push_back(num - '0');
        else h.push_back(num - '0');
    }
    sort(all(s), greater<int>()); sort(all(d), greater<int>()); sort(all(h), greater<int>()); sort(all(c), greater<int>());
    vector<array<pair<int, char>, 2>> ans;
    if (king == 'C') {
        vector<pair<int, char>> nokori;
        while (s.size() >= 2) {
            array<pair<int, char>, 2> tmp;
            tmp[0].first = s.back(); tmp[0].second = 'S';   s.pop_back();
            tmp[1].first = s.back(); tmp[1].second = 'S';   s.pop_back();
            ans.push_back(tmp);
        }
        if (s.size()) nokori.push_back({s[0], 'S'});
        while (d.size() >= 2) {
            array<pair<int, char>, 2> tmp;
            tmp[0].first = d.back(); tmp[0].second = 'D';   d.pop_back();
            tmp[1].first = d.back(); tmp[1].second = 'D';   d.pop_back();
            ans.push_back(tmp);
        }
        if (d.size()) nokori.push_back({d[0], 'D'});
        while (h.size() >= 2) {
            array<pair<int, char>, 2> tmp;
            tmp[0].first = h.back(); tmp[0].second = 'H';   h.pop_back();
            tmp[1].first = h.back(); tmp[1].second = 'H';   h.pop_back();
            ans.push_back(tmp);
        }
        if (h.size()) nokori.push_back({h[0], 'H'});
        if (nokori.size() > c.size()) { cout << "IMPOSSIBLE\n"; return; }
        while (nokori.size()) {
            array<pair<int, char>, 2> tmp;
            tmp[0] = nokori.back(); nokori.pop_back();
            tmp[1].first = c.back(); tmp[1].second = 'C';   c.pop_back();
            ans.push_back(tmp);
        }
        while (c.size()) {
            array<pair<int, char>, 2> tmp;
            tmp[0].first = c.back(); tmp[0].second = 'C';   c.pop_back();
            tmp[1].first = c.back(); tmp[1].second = 'C';   c.pop_back();
            ans.push_back(tmp);
        }
    }
    else if(king == 'H') {
        vector<pair<int, char>> nokori;
        while (s.size() >= 2) {
            array<pair<int, char>, 2> tmp;
            tmp[0].first = s.back(); tmp[0].second = 'S';   s.pop_back();
            tmp[1].first = s.back(); tmp[1].second = 'S';   s.pop_back();
            ans.push_back(tmp);
        }
        if (s.size()) nokori.push_back({s[0], 'S'});
        while (d.size() >= 2) {
            array<pair<int, char>, 2> tmp;
            tmp[0].first = d.back(); tmp[0].second = 'D';   d.pop_back();
            tmp[1].first = d.back(); tmp[1].second = 'D';   d.pop_back();
            ans.push_back(tmp);
        }
        if (d.size()) nokori.push_back({d[0], 'D'});
        while (c.size() >= 2) {
            array<pair<int, char>, 2> tmp;
            tmp[0].first = c.back(); tmp[0].second = 'C';   c.pop_back();
            tmp[1].first = c.back(); tmp[1].second = 'C';   c.pop_back();
            ans.push_back(tmp);
        }
        if (c.size()) nokori.push_back({c[0], 'C'});
        if (nokori.size() > h.size()) { cout << "IMPOSSIBLE\n"; return; }
        while (nokori.size()) {
            array<pair<int, char>, 2> tmp;
            tmp[0] = nokori.back(); nokori.pop_back();
            tmp[1].first = h.back(); tmp[1].second = 'H';   h.pop_back();
            ans.push_back(tmp);
        }
        while (h.size()) {
            array<pair<int, char>, 2> tmp;
            tmp[0].first = h.back(); tmp[0].second = 'H';   h.pop_back();
            tmp[1].first = h.back(); tmp[1].second = 'H';   h.pop_back();
            ans.push_back(tmp);
        }
    }
    else if (king == 'D') {
        vector<pair<int, char>> nokori;
        while (s.size() >= 2) {
            array<pair<int, char>, 2> tmp;
            tmp[0].first = s.back(); tmp[0].second = 'S';   s.pop_back();
            tmp[1].first = s.back(); tmp[1].second = 'S';   s.pop_back();
            ans.push_back(tmp);
        }
        if (s.size()) nokori.push_back({s[0], 'S'});
        while (h.size() >= 2) {
            array<pair<int, char>, 2> tmp;
            tmp[0].first = h.back(); tmp[0].second = 'H';   h.pop_back();
            tmp[1].first = h.back(); tmp[1].second = 'H';   h.pop_back();
            ans.push_back(tmp);
        }
        if (h.size()) nokori.push_back({h[0], 'H'});
        while (c.size() >= 2) {
            array<pair<int, char>, 2> tmp;
            tmp[0].first = c.back(); tmp[0].second = 'C';   c.pop_back();
            tmp[1].first = c.back(); tmp[1].second = 'C';   c.pop_back();
            ans.push_back(tmp);
        }
        if (c.size()) nokori.push_back({c[0], 'C'});
        if (nokori.size() > d.size()) { cout << "IMPOSSIBLE\n"; return; }
        while (nokori.size()) {
            array<pair<int, char>, 2> tmp;
            tmp[0] = nokori.back(); nokori.pop_back();
            tmp[1].first = d.back(); tmp[1].second = 'D';   d.pop_back();
            ans.push_back(tmp);
        }
        while (d.size()) {
            array<pair<int, char>, 2> tmp;
            tmp[0].first = d.back(); tmp[0].second = 'D';   d.pop_back();
            tmp[1].first = d.back(); tmp[1].second = 'D';   d.pop_back();
            ans.push_back(tmp);
        }

    }
    else {
        vector<pair<int, char>> nokori;
        while (d.size() >= 2) {
            array<pair<int, char>, 2> tmp;
            tmp[0].first = d.back(); tmp[0].second = 'D';   d.pop_back();
            tmp[1].first = d.back(); tmp[1].second = 'D';   d.pop_back();
            ans.push_back(tmp);
        }
        if (d.size()) nokori.push_back({d[0], 'D'});
        while (h.size() >= 2) {
            array<pair<int, char>, 2> tmp;
            tmp[0].first = h.back(); tmp[0].second = 'H';   h.pop_back();
            tmp[1].first = h.back(); tmp[1].second = 'H';   h.pop_back();
            ans.push_back(tmp);
        }
        if (h.size()) nokori.push_back({h[0], 'H'});
        while (c.size() >= 2) {
            array<pair<int, char>, 2> tmp;
            tmp[0].first = c.back(); tmp[0].second = 'C';   c.pop_back();
            tmp[1].first = c.back(); tmp[1].second = 'C';   c.pop_back();
            ans.push_back(tmp);
        }
        if (c.size()) nokori.push_back({c[0], 'C'});
        if (nokori.size() > s.size()) { cout << "IMPOSSIBLE\n"; return; }
        while (nokori.size()) {
            array<pair<int, char>, 2> tmp;
            tmp[0] = nokori.back(); nokori.pop_back();
            tmp[1].first = s.back(); tmp[1].second = 'S';   s.pop_back();
            ans.push_back(tmp);
        }
        while (s.size()) {
            array<pair<int, char>, 2> tmp;
            tmp[0].first = s.back(); tmp[0].second = 'S';   s.pop_back();
            tmp[1].first = s.back(); tmp[1].second = 'S';   s.pop_back();
            ans.push_back(tmp);
        }
    }
    for (auto [i, j] : ans) {
        cout << i.first << i.second << " " << j.first << j.second << "\n";
    }
}
signed main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}