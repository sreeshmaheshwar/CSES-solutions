#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
 
	int n, x;
	std::cin >> n >> x;

	std::vector<int> h(n);
	for (int i = 0; i < n; ++i) std::cin >> h[i];

	std::vector<int> s(n);
	for (int i = 0; i < n; ++i) std::cin >> s[i];

	std::vector<int> dp(x + 1);
	for (int i = 0; i < n; ++i)
		for (int j = x; j >= h[i]; --j)
			dp[j] = std::max(dp[j], dp[j - h[i]] + s[i]);

	std::cout << dp[x] << '\n';
 
	return 0;
}