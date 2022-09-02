#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

int main() {
	int n; 
	std::cin >> n;
	std::vector<std::pair<int, int>> tasks(n);
	for (auto &[duration, deadline] : tasks) {
		std::cin >> duration >> deadline;
	}
	std::sort(tasks.begin(), tasks.end());
	long long cur_time = 0, answer = 0;
	for (auto [duration, deadline] : tasks) {
		cur_time += duration;
		answer += deadline - cur_time;
	}
	std::cout << answer << '\n';
	return 0;
}