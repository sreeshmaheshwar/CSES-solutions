#include <iostream>
#include <vector>
#include <algorithm>

struct project {
	int start, end, reward;
};
 
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
 
	int n; std::cin >> n; 
	std::vector<project> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i].start >> a[i].end >> a[i].reward;

	std::sort(a.begin(), a.end(), [](const project& lhs, const project& rhs) {
		return lhs.end < rhs.end;
	});

	std::vector<long long> dp(n), max_reward_before(n), endpoints;
	for (int i = 0; i < n; ++i) {
		int j = (int) (std::lower_bound(endpoints.begin(), endpoints.end(), a[i].start) - endpoints.begin());
		dp[i] = a[i].reward + (j == 0 ? 0 : max_reward_before[j - 1]);
		max_reward_before[i] = std::max(dp[i], (i == 0 ? 0 : max_reward_before[i- 1]));
		endpoints.push_back(a[i].end);
	}
	std::cout << max_reward_before.back() << '\n';
 
	return 0;
}