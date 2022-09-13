#include <iostream>
#include <vector>
const int LOG = 18;

int main() {
	int n, q;
	std::cin >> n >> q;
	std::vector<int> parent(n + 1, -1);
	for (int i = 2; i <= n; ++i) {
		std::cin >> parent[i];
	}
	std::vector<std::vector<int>> binary_jump(LOG + 1, std::vector<int>(n + 1));
	binary_jump[0] = parent;
	for (int jump = 1; jump <= LOG; ++jump) {
		for (int i = 1; i <= n; ++i) {
			int prev_jump = binary_jump[jump - 1][i];
			binary_jump[jump][i] = prev_jump == -1 ? prev_jump : binary_jump[jump - 1][prev_jump];
		}
	}
	while (q--) {
		int x, k;
		std::cin >> x >> k;
		for (int i = 0; i <= LOG && x > 0; ++i) {
			if (k >> i & 1) {
				x = binary_jump[i][x];
			}
		}
		std::cout << x << '\n';
	}
	return 0;
}