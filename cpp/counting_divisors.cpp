#include <iostream>
#include <map>
const int MX_NUM = 1e6;
int lowest_prime_factor[MX_NUM + 1];

// modified sieve of eratosthenes 
void precompute_lpfs() {
	for (int i = 2; i <= MX_NUM; ++i) {
		if (!lowest_prime_factor[i]) {
			for (int j = i; j <= MX_NUM; j += i) {
				if (!lowest_prime_factor[j]) {
					lowest_prime_factor[j] = i;
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
 	
	precompute_lpfs();
	int n; 
	std::cin >> n;
	while (n--) {
		int x; 
		std::cin >> x;
		std::map<int, int> prime_factor;
		while (x > 1) {
			prime_factor[lowest_prime_factor[x]]++;
			x /= lowest_prime_factor[x];
		}
		int ans = 1;
		for (auto &[prime, exponent] : prime_factor) {
			ans *= exponent + 1;
		}
		std::cout << ans << '\n';
	}
 
	return 0;
}