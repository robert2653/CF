#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int maxn = 2e5+5;
// CSES Project Pro Max
void compress(vector<int> &sorted, vector<array<int, 3>> &projects, vector<vector<pii>> &EndProjects, map<int, int> &rev_mp){
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    
    for(int i = 0; i < projects.size(); i++){
        int v = lower_bound(sorted.begin(), sorted.end(), projects[i][1]) - sorted.begin() + 1;
        rev_mp[v] = projects[i][1];
        int u = lower_bound(sorted.begin(), sorted.end(), projects[i][0]) - sorted.begin() + 1;
        rev_mp[u] = projects[i][0];
        EndProjects[v].push_back({u, projects[i][2]});
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<array<int, 3>> projects(n);
    vector<vector<pii>> EndProjects(2 * n + 1);
    vector<int> nums;
    map<array<int, 3>, int> projects_mp;
    for(int i = 0; i < n; i++){
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
        nums.push_back(projects[i][0]);
        nums.push_back(projects[i][1]);
        projects_mp[{projects[i]}] = i + 1;
    }
    map<int, int> rev_mp;
    compress(nums, projects, EndProjects, rev_mp);
    vector<int> dp(nums.size() + 1, 0);
    vector<int> dp_nums(nums.size() + 1, 0);
    vector<int> dp_time(nums.size() + 1, 0);
    vector<int> par(nums.size() + 1, 0);
    vector<int> add(nums.size() + 1, -1);
    for(int end = 1; end <= nums.size(); end++){
        dp[end] = dp[end - 1];
        dp_nums[end] = dp_nums[end - 1];
        dp_time[end] = dp_time[end - 1];
        par[end] = end - 1;
        for(auto [from, gain] : EndProjects[end]){
            if((dp[end] < dp[from] + gain) ||
            (dp[end] == dp[from] + gain && dp_time[end] > dp_time[from] + (rev_mp[end] - rev_mp[from]))){
                dp_nums[end] = dp_nums[from] + 1;
                dp[end] = dp[from] + gain;
                dp_time[end] = dp_time[from] + (rev_mp[end] - rev_mp[from]);
                par[end] = from;
                add[end] = projects_mp[{rev_mp[from], rev_mp[end], gain}];
            }
        }
    }
    std::cout << dp_nums[nums.size()] << " " << dp[nums.size()] << " " << dp_time[nums.size()] << endl;
    int now = nums.size();
    vector<int> ans;
    while(now){
        if(add[now] != -1){
            ans.push_back(add[now]);
        }
        now = par[now];
    }
    sort(ans.begin(), ans.end());
    for(auto &i : ans) cout << i << " ";
}