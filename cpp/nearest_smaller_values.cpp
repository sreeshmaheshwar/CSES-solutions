#include <iostream>
#include <vector>
#include <stack>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::stack<int> stk;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		while (!stk.empty() && a[stk.top()] >= a[i]) {
			stk.pop();
		}
		std::cout << (stk.empty() ? 0 : stk.top() + 1) << " ";
		stk.push(i);
	}

	return 0;
}
