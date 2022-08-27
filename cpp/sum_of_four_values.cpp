#include <iostream>
#include <map>
#include <vector>
#include <utility>

int main() {
	int n, x;
	std::cin >> n >> x;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::map<int, std::pair<int, int>> sum_pos;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int target_sum = x - a[i] - a[j];
			if (sum_pos.count(target_sum)) {
				auto pos = sum_pos[target_sum];
				std::cout << i+1 << " " << j+1 << " " << pos.first+1 << " " << pos.second+1;
				return 0;
			}
		}
		for (int j = 0; j < i; ++j) {
			sum_pos[a[i] + a[j]] = {i, j};
		}
	}
	std::cout << "IMPOSSIBLE";
	return 0;
}
