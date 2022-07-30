#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int modular_inverse_2 = 500000004;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	if (n * (n + 1) % 4) {
		cout << 0 << endl;
	}
	else {
		int target = n * (n + 1) / 4;
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = target - i; j >= 0; --j)
				dp[i + j] = ((long long) dp[i + j] + dp[j]) % MOD;
		}
		cout << (long long) dp[target] * modular_inverse_2 % MOD << '\n';
	}
	return 0;
}