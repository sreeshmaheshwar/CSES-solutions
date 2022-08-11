#include <cassert>
#include <cstdio>

namespace mod_operations {

	const int MOD = 1e9 + 7;
	
	// modular multiplication
	int multiply(int a, int b) {
		return ((long long) a * b) % MOD;
	}

	// binary modular exponentiation
	int pow(int a, int b) {
		int ret = 1;
		while (b) {
			if (b & 1) ret = multiply(ret, a);
			a = multiply(a, a);
			b >>= 1;
		}
		return ret;
	}

	// returns the multiplicative modular inverse of a
	int inverse(int a) { 
		return pow(a, MOD - 2); 
	}
};

const int MAX_FACTORIAL = 1e6;
int factorial[MAX_FACTORIAL + 1], inverse_factorial[MAX_FACTORIAL + 1];

// precomputes all required factorials and their modular inverses
void precompute_factorials() {
	factorial[0] = inverse_factorial[0] =  1;
	for (int i = 1; i <= MAX_FACTORIAL; ++i) {
		factorial[i] = mod_operations::multiply(i, factorial[i - 1]);
		inverse_factorial[i] = mod_operations::inverse(factorial[i]);
	}
}

int binomial_coefficient(int a, int b) {
	assert(0 <= a && a <= MAX_FACTORIAL && 0 <= b && b <= MAX_FACTORIAL);
	return mod_operations::multiply(
		mod_operations::multiply(factorial[a], inverse_factorial[b]), 
		inverse_factorial[a - b]);
}

int main() {
	precompute_factorials();
	int n;
	std::scanf("%d", &n);
	while (n--) {	
		int a, b;
		std::scanf("%d %d", &a, &b);
		std::printf("%d\n", binomial_coefficient(a, b));
	}
	return 0;
}
