#include <iostream>
#include <vector>

int main() {
	int n; 
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	std::vector<int> subseq;
	for (int i = 0; i < n; ++i) {
		auto it = std::lower_bound(subseq.begin(), subseq.end(), a[i]);
		if (it == subseq.end()) {
			subseq.push_back(a[i]);
		} else {
			*it = a[i];
		}
	}
	std::cout << subseq.size() << '\n';
	return 0;
}