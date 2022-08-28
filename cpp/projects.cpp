#include <algorithm>
#include <iostream>
#include <vector>

struct project {
	int start, finish, reward;

	bool operator<(const project &other) const {
		return finish < other.finish;
	}
};

int main() {
	int n; 
	std::cin >> n; 
	std::vector<project> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].start >> a[i].finish >> a[i].reward;
	}
	std::sort(a.begin(), a.end());
	std::vector<long long> max_reward(n + 1); // max_reward[i] is the maximum that can be earned from the first i projects 
	for (int i = 0; i < n; ++i) {
		int j = std::lower_bound(a.begin(), a.end(), project{0, a[i].start, 0}) - a.begin();
		max_reward[i + 1] = std::max(a[i].reward + max_reward[j], max_reward[i]);
	}
	std::cout << max_reward[n] << '\n';
	return 0;
}