#include <iostream>
#include <map>
#include <vector>
#include <utility>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
 
	int n, x;
	std::cin >> n >> x;
	std::vector<int> a(n);
	for (int& element : a) std::cin >> element;
	std::map<int, std::pair<int, int>> sum_position;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int target_sum = x - a[i] - a[j];
			if (sum_position.count(target_sum)) {
				std::cout << i+1 << " " << j+1 << " " << sum_position[target_sum].first+1 << " " << sum_position[target_sum].second+1;
				return 0;
			}
		}
		for (int j = 0; j < i; ++j) {
			sum_position[a[i] + a[j]] = {i, j};
		}
	}
	std::cout << "IMPOSSIBLE";
 
	return 0;
}
