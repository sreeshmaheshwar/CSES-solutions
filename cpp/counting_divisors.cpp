#include <iostream>
#include <map>
const int MX_NUM = 1e6;
int lowest_prime_factor[MX_NUM + 1];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
 	
 	// modified sieve of eratosthenes to compute lowest prime factors
	for (int i = 2; i * i <= MX_NUM; ++i) {
		if (lowest_prime_factor[i]) continue;
		lowest_prime_factor[i] = i;
		for (int j = i * i; j <= MX_NUM; j += i) {
			if (!lowest_prime_factor[j]) lowest_prime_factor[j] = i;
		}
	}
 
	int n; 
	std::cin >> n;
	while (n--) {
		int x; 
		std::cin >> x;
		std::map<int, int> prime_power;
		while (x > 1) {
			if (!lowest_prime_factor[x]) lowest_prime_factor[x] = x;
			prime_power[lowest_prime_factor[x]]++;
			x /= lowest_prime_factor[x];
		}
		int ans = 1;
		for (auto entry : prime_power) ans *= (entry.second + 1);
		std::cout << ans << '\n';
	}
 
	return 0;
}