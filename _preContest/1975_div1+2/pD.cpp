
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<int> arr(n);
		for (auto &x: arr){
			cin >> x;
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			if (i < n - 1 && arr[i] <= arr[i + 1])
				ans = max(ans, arr[i]);
			if (i < n - 2 && arr[i] <= arr[i + 2])
				ans = max(ans, arr[i]);
			if (i - 1 >= 0 && arr[i] <= arr[i - 1])
				ans = max(ans, arr[i]);
			if (i - 2 >= 0 && arr[i] <= arr[i - 2])
				ans = max(ans, arr[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}