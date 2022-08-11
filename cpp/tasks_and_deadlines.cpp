#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
 
	int n; 
	std::cin >> n;
	std::vector<std::pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].first >> a[i].second;
	}
	std::sort(a.begin(), a.end());
	long long cur = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		cur += a[i].first;
		ans += a[i].second - cur;
	}
	std::cout << ans << std::endl;
 
	return 0;
}
