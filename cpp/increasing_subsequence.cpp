#include <iostream>
#include <vector>

int main() {
	int n; 
	std::cin >> n;
	std::vector<int> subseq;
	for (int i = 0, x; i < n; ++i) {
		std::cin >> x;
		auto it = std::lower_bound(subseq.begin(), subseq.end(), x);
		if (it == subseq.end()) {
			subseq.push_back(x);
		} else {
			*it = x;
		}
	}
	std::cout << subseq.size();
	return 0;
}