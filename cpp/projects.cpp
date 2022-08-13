#include <iostream>
#include <vector>
#include <algorithm>

struct project {
	
	int start, finish, reward;

	bool operator<(const project& other) {
		return finish < other.finish;
	}
};

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int n; 
	std::cin >> n; 
	std::vector<project> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].start >> a[i].finish >> a[i].reward;
	}
	std::sort(a.begin(), a.end());
	std::vector<long long> max_reward(n + 1); // maximum money you can earn with the the first i projects 
	for (int i = 0; i < n; ++i) {
		int j = (int) (std::lower_bound(a.begin(), a.end(), project{0, a[i].start, 0}) - a.begin());
		max_reward[i + 1] = std::max(a[i].reward + max_reward[j], max_reward[i]);
	}
	std::cout << max_reward[n] << '\n';

	return 0;
}