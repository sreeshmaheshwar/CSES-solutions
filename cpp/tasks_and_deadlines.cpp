#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
 
	int n; 
	std::cin >> n;
	std::vector<std::pair<int, int>> tasks(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> tasks[i].first >> tasks[i].second;
	}
	std::sort(tasks.begin(), tasks.end());
	long long cur = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		cur += tasks[i].first;
		ans += tasks[i].second - cur;
	}
	std::cout << ans << '\n';
 
	return 0;
}
