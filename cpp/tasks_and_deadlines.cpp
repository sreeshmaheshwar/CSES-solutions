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
	for (auto &[duration, deadline] : tasks) std::cin >> duration >> deadline;
	std::sort(tasks.begin(), tasks.end());
	long long time = 0, answer = 0;
	for (auto &[duration, deadline] : tasks) {
		time += duration;
		answer += deadline - time;
	}
	std::cout << answer << '\n';
 
	return 0;
}
