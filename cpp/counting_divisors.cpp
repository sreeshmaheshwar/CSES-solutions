#include <bits/stdc++.h>
using namespace std;
const int MX_NUM = 1e6;
int lowest_prime_factor[MX_NUM + 1];
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 	
 	// modified sieve of eratosthenes to find lowest prime factors
	for (int i = 2; i * i <= MX_NUM; ++i) {
		if (lowest_prime_factor[i]) continue;
		lowest_prime_factor[i] = i;
		for (int j = i * i; j <= MX_NUM; j += i) {
			if (!lowest_prime_factor[j]) lowest_prime_factor[j] = i;
		}
	}
 
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		map<int, int> prime_power;
		while (x > 1) {
			if (!lowest_prime_factor[x]) lowest_prime_factor[x] = x;
			prime_power[lowest_prime_factor[x]]++;
			x /= lowest_prime_factor[x];
		}
		int ans = 1;
		for (auto [_, power] : prime_power) ans *= (power + 1);
		cout << ans << '\n';
	}
 
	return 0;
}