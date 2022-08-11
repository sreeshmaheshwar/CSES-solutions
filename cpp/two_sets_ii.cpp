#include <iostream>
#include <vector>
const int MOD = 1e9 + 7;

// halves a given number, under modulo MOD
const int MOD_INV_2 = 500000004;
int halve(int a) {
	return ((long long) a * MOD_INV_2) % MOD;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int n; 
	std::cin >> n;
	if (n * (n + 1) % 4) {
		std::cout << 0 << std::endl;
	} else {
		int target_sum = n * (n + 1) / 4;
		std::vector<int> ways_to_sum(target_sum + 1, 0);
		ways_to_sum[0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = target_sum; j >= i; --j) {
				ways_to_sum[j] = ((long long) ways_to_sum[j] + ways_to_sum[j - i]) % MOD;
			}
		}
		std::cout << halve(ways_to_sum[target_sum]) << std::endl;
	}

	return 0;
}