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
	std::map<int, std::pair<int, int>> sum_location;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int target_sum = x - a[i] - a[j];
			if (sum_location.count(target_sum)) {
				auto [k, l] = sum_location[target_sum];
				std::cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << l + 1;
				return 0;
			}
		}
		for (int j = 0; j < i; ++j) {
			sum_location[a[i] + a[j]] = {i, j};
		}
	}
	std::cout << "IMPOSSIBLE";
	return 0;
}
