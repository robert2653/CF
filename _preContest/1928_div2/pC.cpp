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
    int pos, x; cin >> pos >> x;
    // (pos - x) % (2k - 2) == 0, k >= x;
    // (pos + x - 2) % (2k - 2) == 0, k >= x
    int y1 = pos - x, y2 = pos + x - 2;
    set<int> ans;
    int side1 = floor(sqrt(y1));    
    for(int i = 1; i <= side1; i++){
        if(y1 % i == 0){
            int z1 = y1 / i, z2 = i;
            if(z1 % 2 == 0){
                z1 >>= 1;
                if(z1 + 1 >= x) ans.insert(z1 + 1);
            }
            if(z2 % 2 == 0){
                z2 >>= 1;
                if(z2 + 1 >= x) ans.insert(z2 + 1);
            }
        }
    }
    for(int i = 1; i <= side1; i++){
        if(y2 % i == 0){
            int z1 = y2 / i, z2 = i;
            if(z1 % 2 == 0){
                z1 >>= 1;
                if(z1 + 1 >= x) ans.insert(z1 + 1);
            }
            if(z2 % 2 == 0){
                z2 >>= 1;
                if(z2 + 1 >= x) ans.insert(z2 + 1);
            }
        }
    }
    cout << ans.size() << endl; 
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