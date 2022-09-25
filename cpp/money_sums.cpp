#include <iostream>
#include <bitset>
const int MAX_SUM = 1e5;

int main() {
	int n;
	std::cin >> n;
	std::bitset<MAX_SUM + 1> sums;
	sums[0] = 1;
	for (int i = 0, x; i < n; ++i) {
		std::cin >> x;
		sums |= sums << x;
	}
	std::cout << sums.count() - 1 << '\n';
	for (int i = 1; i <= MAX_SUM; ++i) 
		if (sums[i])
			std::cout << i << " ";
	return 0;
}