#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct project {
	
	int start, end, reward;
};
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n; cin >> n; 
	vector<project> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i].start >> a[i].end >> a[i].reward;

	sort(a.begin(), a.end(), [](const project& lhs, const project& rhs) {
		return lhs.end < rhs.end;
	});

	vector<long long> dp(n), max_reward_before(n), ends;
	for (int i = 0; i < n; ++i) {
		int j = (int) (lower_bound(ends.begin(), ends.end(), a[i].start) - ends.begin());
		dp[i] = a[i].reward + (j == 0 ? 0 : max_reward_before[j - 1]);
		max_reward_before[i] = max(dp[i], (i == 0 ? 0 : max_reward_before[i- 1]));
		ends.push_back(a[i].end);
	}
	cout << max_reward_before.back() << '\n';
 
	return 0;
}